#!/usr/bin/env kotlinc -script

@file:DependsOn("libs/gson-2.8.5.jar")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL
import java.util.Locale
import com.google.gson.Gson
import com.google.gson.annotations.SerializedName
import java.io.BufferedInputStream
import java.io.File
import java.io.FileInputStream
import java.io.FileOutputStream
import java.net.URLConnection
import java.security.MessageDigest

/**
 * start of main
 */
val installer = HoYoGameInstaller()
installer.installOrUpdate()
/**
 *
 * end of main
 */

class HoYoGameInstaller() {
    companion object {
        const val GENSHIN_PKG_API_CN = "https://hyp-api.mihoyo.com/hyp/hyp-connect/api/getGamePackages?launcher_id=jGHBHlcOq1&game_ids[]=1Z8W5NHUQb"
        const val GENSHIN_PKG_API_GL = "https://sg-hyp-api.hoyoverse.com/hyp/hyp-connect/api/getGamePackages?launcher_id=VYTpXlbWo8&game_ids[]=gopR6Cufr3"
        const val GENSHIN_PKG_API_BILI = "https://hyp-api.mihoyo.com/hyp/hyp-connect/api/getGamePackages?launcher_id=umfgRO5gh5"
        const val ZZZ_PKG_API_CN = "https://hyp-api.mihoyo.com/hyp/hyp-connect/api/getGamePackages?launcher_id=jGHBHlcOq1&game_ids[]=x6znKlJ0xK"
        const val ZZZ_PKG_API_GL = "https://sg-hyp-api.hoyoverse.com/hyp/hyp-connect/api/getGamePackages?launcher_id=VYTpXlbWo8&game_ids[]=U5hbdsT9W7"

        const val GENSHIN_CN = 0
        const val GENSHIN_GL = 1
        const val GENSHIN_BILI = 2
        const val ZZZ_CN = 3
        const val ZZZ_GL = 4
        const val INVALIDE_GAME = -1

        const val GAME_WINE_INSTALL_PATH = "Contents/SharedSupport/prefix/drive_c/HoYoGame/"

        val game_api_mapping = hashMapOf(GENSHIN_CN to GENSHIN_PKG_API_CN,
                GENSHIN_GL to GENSHIN_PKG_API_GL,
                GENSHIN_BILI to GENSHIN_PKG_API_BILI,
                ZZZ_CN to ZZZ_PKG_API_CN,
                ZZZ_GL to ZZZ_PKG_API_GL)

        val language: String get() {
            return Locale.getDefault().language
        }

        val chooseGameGuide: String get() = if (language == "zh") {
            "选择你要安装的游戏：\n" +
                    "原神（国服）：0\n" +
                    "原神（国际服）：1\n" +
                    "原神（bili服）：2\n" +
                    "绝区零（国服）：3\n" +
                    "绝区零（国际服）：4"
        } else {
            "Choose the game you want to install:\n" +
                    "Genshin Impact (CN server): 0\n" +
                    "Genshin Impact (Global server): 1\n" +
                    "Genshin Impact (Bilibili server): 2\n" +
                    "Zenless Zone Zero (CN server): 3\n" +
                    "Zenless Zone Zero (Global server): 4"
        }

        val invalidChoiceGuide: String get() = if (language == "zh") {
            "请输入有效的选择！"
        } else {
            "Please enter a valid choice!"
        }

        //游戏数据包的默认下载路径
        val gamePkgsBaseDir: String get() = "${System.getProperty("user.home")}/Downloads/HoYoGamePacks/"
    }

    private var gameToInstall = INVALIDE_GAME

    private var version: String = ""

    private var installedVersion: String = ""

    private var totalSize: Long = 0

    private val pkgUrls = mutableListOf<String>()
    private val pkgMd5s = mutableListOf<String>()


    private var pkgZipFileName: String? = null
    private var splitPkgZipFileName = mutableListOf<String>()

    private var appInstallationPath: String? = null

    private var appName = ""

    fun installOrUpdate() {
        chooseGame()
        fetchPkgInfo()
        installApp()
        downloadGamePkgs()
        unZipGamePkgs("/Applications/$appName/$GAME_WINE_INSTALL_PATH")
    }

    fun chooseGame() {
        println(chooseGameGuide)
        while (!isValidGame(gameToInstall)) {
            readLine()?.toInt()?.let {
                gameToInstall = it
                if (!isValidGame(gameToInstall)) {
                    println(invalidChoiceGuide)
                }
            }
        }
    }

    fun installApp(): Boolean {
        appName = "${getAppName(gameToInstall)}.app"
        val appFileName = when (gameToInstall) {
            in GENSHIN_CN .. GENSHIN_BILI -> {
                "GS.app"
            }
            in ZZZ_CN .. ZZZ_GL -> {
                "ZZZ.app"
            }
            else -> {
                ""
            }
        }
        val sourceFile = File(appFileName)
        val destFolder = File("/Applications/")
        if (!sourceFile.exists()) {
            println("$appFileName  does not exist!")
            return false
        }
        if (!destFolder.exists() || !destFolder.isDirectory) {
            println("$destFolder  does not exist!")
            return false
        }

        val destFile = File(destFolder, appName)
        appInstallationPath = destFile.absolutePath

        try {
            val installPb = ProcessBuilder(
                "/bin/cp",
                "-R",
                sourceFile.absolutePath,
                destFile.absolutePath
            )

            if (destFile.exists()) {
                println("Please delete exist Apps before installation!")
                return false
            }

            println("Installing App ...")
            val process = installPb.start()
            val exitCode = process.waitFor()

            if (exitCode == 0) {
                println("Install App success!")
                return true
            } else {
                println("Install App failed：$exitCode")
                return false
            }
        } catch (e: Exception) {
            println("Install App failed：${e.message}")
            e.printStackTrace()
            return false
        }
    }

    fun downloadGamePkgs() {
        println("数据包总大小：${totalSize / 1024 / 1024 / 1024} GB，请预留至少两倍数据包大小的空间以正常安装游戏")
        var pkgCount = 0
        val downloadDir = File(gamePkgsBaseDir)
        if (!downloadDir.exists()) {
            downloadDir.mkdir()
        }
        for (url in pkgUrls) {
            pkgCount ++
            while (!downloadPkg(url, gamePkgsBaseDir, pkgCount)) {
                println("Download fail, retry in 2s")
                Thread.sleep(2000)
            }
        }
        println("所有文件已下载完成，准备解压")
    }

    private fun downloadPkg(pkgUrl: String, destPath: String, pkgCount: Int): Boolean {
        try {
            val url = URL(pkgUrl)
            val connection = url.openConnection()
            connection.connect()

            var startTime: Long = 0
            var currentTime: Long = 0

            var lastDownloadSize = 0L

            var downloadedSize: Long = 0

            // 获取文件名
            val fileName = getFileName(pkgUrl, connection)
            if (fileName.isEmpty()) {
                println("无法获取下载文件名")
                return false
            }

            if(!splitPkgZipFileName.contains(fileName)) {
                splitPkgZipFileName.add(fileName)
            }

            initPkgZipFileName(fileName)

            if (File(gamePkgsBaseDir + pkgZipFileName).exists()) {
                //已存在待解压的合并包，不下载数据
                return true
            }

            val destFilePath = destPath + fileName

            if (!checkShouldDownload(fileName, pkgCount)) {
                return true
            }

            // 获取文件总大小
            val fileSize = connection.contentLengthLong
            println("单包大小：${fileSize / 1024 / 1024 / 1024} GB")

            startTime = System.currentTimeMillis()
            BufferedInputStream(connection.getInputStream()).use { input ->
                FileOutputStream(destFilePath).use { output ->
                    val buffer = ByteArray(1024 * 32)
                    var bytesRead: Int
                    while (input.read(buffer).also { bytesRead = it } != -1) {
                        output.write(buffer, 0, bytesRead)
                        downloadedSize += bytesRead
                        currentTime = System.currentTimeMillis()

                        if (currentTime - startTime >= 1000L) {
                            printDownloadProgress(downloadedSize, fileSize, fileName, (downloadedSize - lastDownloadSize) / 1024f / 1024f)
                            startTime = System.currentTimeMillis()
                            lastDownloadSize = downloadedSize
                        }
                    }
                }
            }
            val verifyDownload = checkShouldDownload(fileName, pkgCount)
            if (verifyDownload) {
                File(destFilePath).delete()
            } else {
                println("\n文件下载完成：$destFilePath}")
                println("")
            }
            return !verifyDownload
        } catch (e: Exception) {
            println("\n文件下载失败：${e.message}")
            e.printStackTrace()
            return false
        }
    }

    //检查某个分包是否需要重新下载
    private fun checkShouldDownload(pkgName: String, pkgCount: Int): Boolean {
        //当某个序号的分包不存在或者存在但md5校验不通过时需要重新下载
        val targetFile = File(gamePkgsBaseDir + pkgName)
        if (!targetFile.exists()) {
            return true
        }

        println("\n正在校验资源文件：$pkgName\n")

        val targetMd5 = calculateMD5(targetFile)

        if (targetMd5 != pkgMd5s[pkgCount - 1]) {
            targetFile.delete()
            return true
        }

        return false
    }

    private fun calculateMD5(file: File): String {
        val digest = MessageDigest.getInstance("MD5")
        val inputStream = FileInputStream(file)
        val buffer = ByteArray(8192)
        var read = 0

        while (inputStream.read(buffer).also { read = it } > 0) {
            digest.update(buffer, 0, read)
        }

        val md5sum = digest.digest()
        val hexString = StringBuilder()

        for (i in md5sum.indices) {
            hexString.append(String.format("%02x", md5sum[i]))
        }

        inputStream.close()
        return hexString.toString().toUpperCase()
    }

    // 打印下载进度
    private fun printDownloadProgress(downloaded: Long, total: Long, fileName: String, speed: Float) {
        val progress = (downloaded.toFloat() / total * 100).toInt()
        print("\r正在下载：$fileName,下载进度：$progress%,下载速度：$speed MB/s")
        System.out.flush()
    }

    // 从 URL 和连接中获取文件名
    private fun getFileName(url: String, connection: URLConnection): String {
        var fileName = ""
        // 从 URL 中获取文件名
        val urlPath = URL(url).path
        val slashIndex = urlPath.lastIndexOf('/')
        if (slashIndex >= 0 && slashIndex < urlPath.length - 1) {
            fileName = urlPath.substring(slashIndex + 1)
        }

        // 如果获取不到，从连接中获取 Content-Disposition 中的文件名
        if (fileName.isEmpty()) {
            val disposition = connection.getHeaderField("Content-Disposition")
            if (disposition != null && disposition.contains("filename=")) {
                fileName = disposition.substring(disposition.indexOf("filename=") + 9)
                fileName = fileName.replace("\"", "")
            }
        }

        return fileName
    }

    fun unZipGamePkgs(destDir: String) {
        // 创建输出目录
        val outputDirFile = File(destDir)
        if (outputDirFile.exists()) {
            println("正在删除已安装的游戏资源 ...")
            outputDirFile.deleteRecursively()
        }
        if (!outputDirFile.exists()) {
            outputDirFile.mkdirs()
        }

        catAllSplitZipFiles()

        pkgZipFileName?.let {
            val unzipArgs = mutableListOf<String>()
            unzipArgs.add(it)
            unzipArgs.add("-d")
            unzipArgs.add(outputDirFile.absolutePath)

            val processBuilder = ProcessBuilder("unzip", *unzipArgs.toTypedArray())
                .directory(File(gamePkgsBaseDir))
                .redirectOutput(ProcessBuilder.Redirect.INHERIT)
                .redirectError(ProcessBuilder.Redirect.INHERIT)

            println("正在解压游戏文件 ...")
            val process = processBuilder.start()
            val exitCode = process.waitFor()

            if (exitCode == 0) {
                println("解压完成")
                //解压完成后删除压缩包
                File(gamePkgsBaseDir + it).delete()
            } else {
                println("解压过程中出现错误，退出码：$exitCode")
            }
        }
    }

    private fun catAllSplitZipFiles() {
        val splitZipPkgs = mutableListOf<File>()
        for (name in splitPkgZipFileName) {
            val pkg = File(gamePkgsBaseDir + name)
            if (pkg.exists()) {
                splitZipPkgs.add(pkg)
            }
        }
        pkgZipFileName?.let { it ->
            try {
                val destFile = File(gamePkgsBaseDir + it)
                if (splitZipPkgs.size == splitPkgZipFileName.size) {
                    FileOutputStream(destFile).channel.use { outputChannel ->
                        for (splitPkg in splitZipPkgs) {
                            println("正在合并资源文件${splitPkg.name} ... ")
                            val inputChannel = FileInputStream(splitPkg).channel
                            outputChannel.transferFrom(inputChannel, outputChannel.size(), inputChannel.size())
                            inputChannel.close()
                        }
                        outputChannel.close()
                    }
                    for (splitPkg in splitZipPkgs) {
                        //合包完成后删除所有分包
                        splitPkg.delete()
                    }
                } else {
                    if (splitZipPkgs.size != 0) {
                        println("资源包缺失，请重新下载！")
                    }
                }
            } catch (e: Exception) {
                println("Error merging files: ${e.message}")
            }
        }
    }

    fun fetchPkgInfo() {
        val url = URL(game_api_mapping[gameToInstall])
        val connection = url.openConnection() as HttpURLConnection
        connection.requestMethod = "GET"

        val responseCode = connection.responseCode

        if (responseCode == HttpURLConnection.HTTP_OK) {
            val inputStream = connection.inputStream
            val reader = BufferedReader(InputStreamReader(inputStream))
            val jsonString = reader.use { it.readText() }
            val response = Gson().fromJson(jsonString, ApiResponse::class.java)
            version = response.data.gamePackages[0].pkgInfo.mainPkgInfo.version
            for (pkg in response.data.gamePackages[0].pkgInfo.mainPkgInfo.gamePkgs) {
                pkgUrls.add(pkg.url)
                pkgMd5s.add(pkg.md5.toUpperCase())
                totalSize += pkg.size.toLong()
            }
        } else {
            println("request fail")
        }

        connection.disconnect()
    }

    private fun isValidGame(gameCode: Int) = gameCode in GENSHIN_CN .. ZZZ_GL

    private fun getAppName(gameCode: Int) = when (gameCode) {
        in GENSHIN_CN .. GENSHIN_BILI -> {
            if (language == "zh") {
                "原神"
            } else {
                "Genshin Impact"
            }
        }
        in ZZZ_CN .. ZZZ_GL -> {
            if (language == "zh") {
                "绝区零"
            } else {
                "Zenless Zone Zero"
            }
        }
        else -> {
            ""
        }
    }

    private fun initPkgZipFileName(splitName: String) {
        val lastDotIndex = splitName.lastIndexOf(".")
        if (pkgZipFileName.isNullOrEmpty()) {
            pkgZipFileName = splitName.substring(0, lastDotIndex)
        }
    }
}

// dataBeans
data class SplitPkgInfo(val url: String, val md5: String, val size: String, @SerializedName("decompressed_size") val decompressedSize: String)

data class GameMainPkgInfo(val version: String, @SerializedName("game_pkgs") val gamePkgs: List<SplitPkgInfo>)

data class GamePkgInfo(@SerializedName("major") val mainPkgInfo: GameMainPkgInfo)

data class GameBaseInfo(val id: String, val biz: String)

data class GamePackage(@SerializedName("game") val baseInfo: GameBaseInfo, @SerializedName("main") val pkgInfo: GamePkgInfo)

data class GameData(@SerializedName("game_packages") val gamePackages: List<GamePackage>)

data class ApiResponse(val retcode: Int, val message: String, val data: GameData)

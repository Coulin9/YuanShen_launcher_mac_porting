#!/usr/bin/env kotlinc -script

@file:DependsOn("libs/gson-2.8.5.jar")
@file:DependsOn("libs/HoyoChunkInstaller-1.0.0.jar")

import java.util.Locale
import java.io.File
import javax.swing.JFileChooser
import javax.swing.UIManager
import javax.swing.filechooser.FileSystemView
import javax.swing.SwingUtilities
import kotlin.system.exitProcess
import com.coulin.hoyochunkinstaller.Installer
import com.coulin.hoyochunkinstaller.Constants

/**
 * start of main
 */
val installer = HoYoGameInstaller()
installer.installOrUpdate()
/**
 *
 * end of main
 */

class HoYoGameInstaller {
    companion object {
        const val INVALIDE_GAME = -1

        const val GS_EXE = "/YuanShen.exe"
        const val ZZZ_EXE = "/ZenlessZoneZero.exe"

        const val WINE_DRIVE_C_PATH = "Contents/SharedSupport/prefix/drive_c/"
        const val LAUNCH_BAT = "launchGame.bat"
        const val WINE_MAC_ROOT_PATH = "Z:"
        const val MAC_APPLICATION_PATH = "/Applications/"

        const val GS_CLOUD_GAME_PARAM = "" //no need to add this

        val language: String
            get() {
                return Locale.getDefault().language
            }

        val gameIdMap = hashMapOf<Int, Int>().apply {
            this[0] = Constants.GameId.GENSHIN_CN
            this[1] = Constants.GameId.ZZZ_CN
        }

        val chooseGameGuide: String
            get() = if (language == "zh") {
                "选择你要安装的游戏：\n" +
                        "原神（国服）：0\n" +
                        "绝区零（国服）：1"
            } else {
                "Choose the game you want to install:\n" +
                        "Genshin Impact (CN server): 0\n" +
                        "Zenless Zone Zero (CN server): 1"
            }

        val invalidChoiceGuide: String
            get() = if (language == "zh") {
                "请输入有效的选择！"
            } else {
                "Please enter a valid choice!"
            }

        //游戏数据包的默认下载路径
        var gamePkgsBaseDir = ""

        var hasSelectedGameFolder = false
    }

    private var gameToInstall = INVALIDE_GAME

    private var appInstallationPath: String? = null

    private var appName = ""

    fun installOrUpdate() {
        SwingUtilities.invokeLater {
            chooseGame()
            installApp()
            selectGameDataFolder()
            downloadGameByChunk()
            exitProcess(0)
        }
    }

    fun chooseGame() {
        println(chooseGameGuide)
        while (!isValidGame(gameToInstall)) {
            readLine()?.toInt()?.let {
                gameToInstall = gameIdMap[it] ?: -1
                if (!isValidGame(gameToInstall)) {
                    println(invalidChoiceGuide)
                }
            }
        }
    }

    fun installApp(): Boolean {
        appName = "${getAppName(gameToInstall)}.app"
        val appFileName = when (gameToInstall) {
            Constants.GameId.GENSHIN_CN -> {
                "GS.app"
            }

            Constants.GameId.ZZZ_CN -> {
                "ZZZ.app"
            }

            else -> {
                ""
            }
        }
        val sourceFile = File(appFileName)
        val destFolder = File(MAC_APPLICATION_PATH)
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

            val deletePb = ProcessBuilder(
                "/bin/rm",
                "-R",
                destFile.absolutePath
            )

            if (destFile.exists()) {
                println("Updating game ...")
                println("Deleting existing App ...")
                val extCode = deletePb.start().waitFor()
                if (extCode == 0) {
                    println("Delete existing App success!")
                } else {
                    println("Delete existing App failed: $extCode!,Please delete App manually.")
                    return false
                }
            } else {
                println("Barand new installation ...")
            }

            println("Installing App ...")
            val exitCode = installPb.start().waitFor()

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

    fun selectGameDataFolder() {
        println("选择游戏安装路径：")
        val path = selectFolder()
        if (path != null) {
            hasSelectedGameFolder = true
            gamePkgsBaseDir = "$path/HoYoGamePacks/"
            println("游戏安装路径是：$gamePkgsBaseDir")
        }
        modifyLaunchBat()
    }

    private fun selectFolder(): String? {
        // 设置为系统外观
        UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName())

        // 创建文件选择器实例
        val chooser = JFileChooser(FileSystemView.getFileSystemView())
        chooser.fileSelectionMode = JFileChooser.DIRECTORIES_ONLY // 仅允许选择目录

        // 显示选择窗口
        val returnValue = chooser.showOpenDialog(null)
        if (returnValue == JFileChooser.APPROVE_OPTION) {
            return chooser.selectedFile.absolutePath // 返回选中目录的路径
        }

        // 如果取消或关闭窗口，返回 null
        return null
    }

    private fun modifyLaunchBat() {
        if (!hasSelectedGameFolder) {
            return
        }
        val launchBatPath =
            "$MAC_APPLICATION_PATH${getAppName(gameToInstall)}.app/$WINE_DRIVE_C_PATH$LAUNCH_BAT"
        val launchString =
            "\"$WINE_MAC_ROOT_PATH$gamePkgsBaseDir${getExeFileName(gameToInstall)}\"" + if (isGS(
                    gameToInstall
                )
            ) " " + GS_CLOUD_GAME_PARAM else ""
        val launchBatFile = File(launchBatPath)
        launchBatFile.writeText(launchString)
    }

    fun downloadGameByChunk() {
        Installer.install(gameToInstall, gamePkgsBaseDir)
    }

    private fun isValidGame(gameCode: Int) = gameCode in Constants.GameId.GENSHIN_CN..Constants.GameId.ZZZ_CN

    private fun getAppName(gameCode: Int) = when (gameCode) {
        Constants.GameId.GENSHIN_CN -> {
            if (language == "zh") {
                "原神"
            } else {
                "Genshin Impact"
            }
        }

        Constants.GameId.ZZZ_CN -> {
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

    private fun getExeFileName(gameCode: Int) = when (gameCode) {
        Constants.GameId.GENSHIN_CN -> {
            GS_EXE
        }

        Constants.GameId.ZZZ_CN -> {
            ZZZ_EXE
        }

        else -> {
            ""
        }
    }

    private fun isGS(gameCode: Int) = gameCode == Constants.GameId.GENSHIN_CN

}

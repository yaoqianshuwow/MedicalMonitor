# MedicalMonitor

一个可直接运行的 Qt 6 Widgets 医用参数监护教学项目。程序默认启动模拟数据源，无需串口设备即可演示 ECG1、ECG2、SpO₂、Resp 四路连续扫描波形、生命体征、无创血压测量流程与 CSV 记录。

> **重要声明：本项目仅用于 Qt 编程与医用仪器软件流程教学。所有模拟数值不具备医学意义，不用于医疗诊断、治疗或临床决策。**

## 功能

- 可复用 `WaveformWidget` 自绘控件，提供回绕扫描和游标前方擦除缝；
- 两路带少量噪声与相位差的 P-QRS-T 心电波；
- 血氧脉搏波与低频呼吸波；
- 心率、无创血压、SpO₂、呼吸率、T1/T2 双路体温；
- 模拟 NIBP 充气、缓慢放气、停止和结果生成完整流程；
- 串口枚举及波特率、数据位、校验位、停止位设置，安全打开/关闭；
- CSV 连续保存模拟采样；串口模式下保存带时间戳的原始十六进制字节；
- 退出时停止定时器、刷新并关闭 CSV、关闭串口。

## 已验证 Kit

- Qt：6.2.4 Open Source，`C:\Qt\6.2.4\mingw_64`
- qmake：3.1，`C:\Qt\6.2.4\mingw_64\bin\qmake.exe`
- 编译器：MinGW-w64 11.2.0，`C:\Qt\Tools\mingw1120_64`
- 必需模块：Core、Gui、Widgets；串口使用项目内 Win32 兼容层

本机的 Qt 6.2.4 Kit 未安装可选的官方 Qt SerialPort 模块，所以工程默认启用 `compat/serialport`，仍能枚举、配置和打开 Windows COM 端口。如果 Kit 已安装官方模块，可给 qmake 增加 `CONFIG+=use_qt_serialport`，此时 `.pro` 会启用 `QT += serialport` 并排除兼容层。

在 Qt Creator 中直接打开 `MedicalMonitor.pro`，选择 **Desktop Qt 6.2.4 MinGW 64-bit** Kit 后构建运行即可。

## 命令行构建

在 PowerShell 中运行：

```powershell
cd C:\Users\28407\Desktop\cpp\MedicalMonitor
New-Item -ItemType Directory -Force build-release | Out-Null
cd build-release
& C:\Qt\6.2.4\mingw_64\bin\qmake.exe ..\MedicalMonitor.pro CONFIG+=release
& C:\Qt\Tools\mingw1120_64\bin\mingw32-make.exe -j4
```

生成的程序位于 `build-release\bin\MedicalMonitor.exe`。在开发机运行前，把 Qt 与 MinGW 加入本次终端的 `PATH`：

```powershell
$env:Path = "C:\Qt\6.2.4\mingw_64\bin;C:\Qt\Tools\mingw1120_64\bin;" + $env:Path
.\bin\MedicalMonitor.exe
```

如果要复制到没有安装 Qt 的电脑，在 `build-release` 目录执行：

```powershell
& C:\Qt\6.2.4\mingw_64\bin\windeployqt.exe --release .\bin\MedicalMonitor.exe
```

可选的自动化冒烟测试会在后台跑完一次 NIBP 充放气流程，同时记录模拟采样；成功时退出码为 0：

```powershell
.\bin\MedicalMonitor.exe --smoke-test .\smoke-test.csv
```

需要生成界面快照用于教学材料时，可运行：

```powershell
.\bin\MedicalMonitor.exe --screenshot .\monitor-preview.png
```

## 使用说明

程序启动即进入绿色标识的 `SIM 模拟数据` 模式。

1. 选择“测量 → 无创血压测量”，点击“开始测量”观察袖带压力先升后降；测量中可随时停止。
2. 选择“存储 → 开始 CSV 记录”，指定文件名；再次选择同一菜单即停止并落盘。CSV 仅写实际采集行，含 UTC 时间戳。
3. 选择“数据源 → 串口设置”可刷新端口并设置参数。成功打开后模拟器停止；“切换到模拟数据”会安全关闭串口并恢复模拟器。
4. 真实串口模式会记录 `readyRead()` 收到的原始字节。不同教学硬件协议并不统一，如需把字节解码为界面参数，应按设备协议在 `MainWindow::readSerialData()` 中接入对应的解包与模块分发器。

## 目录结构

```text
MedicalMonitor/
├─ MedicalMonitor.pro
├─ main.cpp
├─ mainwindow.h/.cpp
├─ widgets/              # 波形与参数卡片
├─ datasource/           # 非阻塞模拟数据源
├─ dialogs/              # 串口与血压测量对话框
├─ storage/              # CSV 记录器
└─ protocol/             # 生命体征数据模型
```

## CSV 字段

模拟行包含时间戳、4 路波形采样、各项生命体征和袖带压力。串口行的 `source` 为 `serial`，`raw_hex` 保留原始十六进制字节，便于协议排查；未采集到的数据不会写入占位行。

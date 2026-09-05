# data_structure

个人 C/C++ 数据结构、算法与课程练习合集，同时保留 CS:APP 实验材料及部分历史项目快照。各目录按课程或练习来源组织，通常以单个源文件作为程序入口。

## 目录导航

| 目录 / 文件 | 内容 |
| --- | --- |
| [data_structure](data_structure/) | 数据结构课程练习、在线实验与复习题 |
| [advanced_language/advanced_program_design](advanced_language/advanced_program_design/) | C++ 程序设计练习及配套头文件 |
| [CSAPP](CSAPP/) | 系统课程练习、Data Lab 和性能实验代码 |
| [luogu](luogu/) | 洛谷题目练习 |
| [primer plus](primer%20plus/) | C++ 学习练习 |
| [lecture](lecture/) | 课程材料与示例 |
| [calculaor/BigInteger.cpp](calculaor/BigInteger.cpp) | 大整数相关代码；目录名沿用原有拼写 |
| [count_sort.cpp](count_sort.cpp) | 计数排序独立示例 |
| [tasktuner](tasktuner/) | TaskTuner 历史项目快照 |

## 运行一个 C++ 示例

准备支持 C++17 的 `g++`。以下 Windows PowerShell 命令从仓库根目录执行：

```powershell
g++ -std=c++17 -Wall -Wextra count_sort.cpp -o count-sort-local.exe
.\count-sort-local.exe
```

此示例使用源码内置数组，输出排序结果 `1 2 2 3 5 6 7 9`。

Linux / macOS：

```sh
g++ -std=c++17 -Wall -Wextra count_sort.cpp -o count-sort-local
./count-sort-local
```

其他程序可能需要标准输入、额外头文件或特定工作目录，请先阅读各自源码。多个文件可能分别定义 `main`，不能将整个仓库作为一个程序一起链接。

## CS:APP Data Lab

原始说明位于 [CSAPP/datalab-handout/README](CSAPP/datalab-handout/README)。在与课程工具兼容的 Linux / WSL 环境中，进入该目录后可按说明构建和检查：

```sh
cd CSAPP/datalab-handout
make btest
./btest
./dlc bits.c
```

`btest` 检查函数结果，`dlc` 检查操作符等作业限制。所需编译环境和规则以实验自带文件为准。

## 使用范围

- 仓库保留个人练习与试验版本，未提供全仓库统一构建或全部题目通过的验证记录。
- `.vscode` 中的工具路径可能依赖原开发机器；本地编译时按自己的环境调整。
- 已有二进制、缓存和历史项目依赖不代表可复现的运行环境，建议从选定示例的源码开始。
- 课程提供的框架与材料保留原有说明和归属。

# 计算机组织与体系结构实习Lab 1: 处理器性能评测

麦景

1700012751

------

>  一. 我们针对系统评测的不同角度会采用不同的评测程序. 在目前已有的评测程序中, 为下列评测目标找到某些合适的评测程序(列出即可).

| 评测目标           | 评测程序                                  | 评测目标           | 评测程序                |
| ------------------ | ----------------------------------------- | ------------------ | ----------------------- |
| CPU整点性能        | CINT2017                                  | CPU浮点性能        | CFP2017                 |
| 计算机事务处理能力 | TPC-E                                     | 嵌入式系统计算能力 | Dhrystone, EEMBC        |
| 2D处理能力         | GFXBench2D                                | 3D处理能力         | SPECapc, GFXBench3D     |
| 并行计算性能       | SPECrate, ACCEL, MPI2007, OMP2012         | 系统响应速度       |                         |
| 编译优化能力       |                                           | 操作系统性能       |                         |
| 多媒体处理能力     | SiSoftware Sandra                         | IO处理能力         | TPC-C, TPC-W, SPECsfs97 |
| 浏览器性能         | [BrowserBench](https://browserbench.org/) | 网络传输速率       | netperf                 |
| Java运行环境性能   | SPECjbb2015                               | 邮件服务性能       | SPECmail                |
| 文件服务器性能     | SPECSFS                                   | Web服务器性能      | SPECWeb                 |
| 服务器功耗和性能   | SPCEpower_sjj2008, TPC-Energy             |                    |                         |

> *Conception: **SPECRatio***(<u>use geometric means</u>)
>
> Using the geometric mean ensures two important properties:
>
> 1. the geometric mean of ratios = the ratio of the geometric means
> 2. The choice of the reference computer is irrelevant.
>
> ![image-20200222165944670](./lab1_report.assets/image-20200222165944670.png)

*Credit to:*

- *Computer Architecture: A Quantitative Approach*, Chapter 1.8 & Appendix D
- [The Standard Performance Evaluation Corporation (SPEC)](http://spec.org/)
- [Transaction-processing Concil(TPC)](http://www.tpc.org)
- [Unified cross-platform 3D graphics benchmark database](https://gfxbench.com/)



> 二. 阅读文献（*Reinhold P.Weicker, An Overview of Common Benchmarks, IEEE Computer, December 1990.*）并回答下面的问题:
>
> 1. 简述用于性能评测的MIPS指标之含义，以及它是如何被计算的.
> 2. 使用Linux下的剖视工具（例如`gprof`）对`dhrystone`和`whetstone`进行剖视，参考论文Table 1形式给出数据，你的结果和该论文是否一致，为什么？
> 3. 论文中讨论了处理器之外可能对性能造成影响的因素，请分别使用两种不同的语言（例如C和Java）使用同一算法实现快速排序、矩阵乘法、求Ackermann函数，验证文中的观点。（请保留你的程序，我们在后面可能还会用到它)

1. MIPS字面意思是 millions of instructions per second, 但是随着CISC的出现逐渐失去了意义. 现在重新定义"VAX MIPS", 度量性能与VAX 11/780之间的比值. 运行评测程序需要控制的变量有编程语言, 编译器, 评测角度等.

2. 

#### whetstone

由于`gprof`采样频率过低(采样周期为0.01s), 无法记录单次执行时间少于0.01s的函数. 我们采用`vtune`进行profile. 假设`amplxe-cl`已在路径当中:

```shell
$ cd whetstone
$ make debug
$ amplxe-cl -V
$ amplxe-cl -collect hotspots ./debug/whetdc 300000
$ amplxe-cl -report hotspots -format=csv  > whetstone_300000.csv
```

整理后的statistics如下:

| 行标签                  | 求和项:CPU Time | Percent |                   |        |
| ----------------------- | --------------- | ------- | ----------------- | ------ |
| main                    | 5.030017        | 33.99%  |                   |        |
| P3                      | 1.599985        | 10.81%  |                   |        |
| P0                      | 0.529996        | 3.58%   |                   |        |
| PA                      | 0.599998        | 4.05%   | User Code         | 52.43% |
| Trigonometric functions | 2.979982        | 20.14%  |                   |        |
| Other math functions    | 4.040002        | 27.30%  | Library functions | 47.43% |
| Others                  | 0.020002        | 0.14%   |                   |        |
| 总计                    | 14.799982       | 100.00% |                   |        |

完整数据见[此](./whetstone/whetstone_300000.xlsx). 其与论文中给的数据基本一致, 验证了不同编译器也会对同样的评测程序的结果产生影响. 但在具体结果上还能看出细微差别, 比如P0(Indexing)时间占比远小于论文中的数据.




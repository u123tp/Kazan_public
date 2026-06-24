# Kazan
## 概要
 xv6を実行することができるRV64IMAのプロセッサ。<br>
 以下の特徴を持ちます。<br>
 - OoOな命令実行
 - 4命令同時フェッチ
 - Sv39によるアドレス変換
 - ノンブロッキングキャッシュ
 - ノンブロッキングTLB
 - 1ld/1stのlsu
 

## 環境
```
$ cat /etc/os-release 
PRETTY_NAME="Ubuntu 24.04.3 LTS"
NAME="Ubuntu"
VERSION_ID="24.04"
VERSION="24.04.3 LTS (Noble Numbat)"
VERSION_CODENAME=noble
ID=ubuntu
ID_LIKE=debian
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
UBUNTU_CODENAME=noble
LOGO=ubuntu-logo

$ verilator --version
Verilator 5.039 devel rev v5.038-19-gcefe1845d

$ /tools/Xilinx/Vivado/2024.2/bin/vivado -version
vivado v2024.2 (64-bit)
Tool Version Limit: 2024.11
SW Build 5239630 on Fri Nov 08 22:34:34 MST 2024
IP Build 5239520 on Sun Nov 10 16:12:51 MST 2024
SharedData Build 5239561 on Fri Nov 08 14:39:27 MST 2024
Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.

```
 

## xv6のコンパイル方法
 以下のコマンドでコンパイル&メモリで読み込む位置にhexファイルにして配置.
```
$ cd xv6-riscv-revised
$ make qemu
$ cd ..
$ cp xv6-riscv-revised/kernel/kernel kernel/elf/kernel
$ cd kernel 
$ ./elf2hex.sh
```

## verilator上での実行方法
 Verilatorを入れた上で以下のコマンドを実行.
```
$ cd src
$ make run
```

## kv260上での実行方法
FPGAで実行するためには,まずbitstreamを生成後,それを含めてhardwareをexport.

vivadoでplに回路を書き込む。

Vitisを起動し,workspaceを任意のフォルダに指定.
New component => platform でさっき出力したhardwareファイル(.xsa)を読み込む.
xilffにチェックをつけて,platformをbuildした後,vitis_srcにある内容をmain.cとしてappを作成.
buildしたら,applicationファイルができているので,kv260をpcにつないで,
$ xsdb ps_dram_initializer.tcl
を実行.こうすることで,kv260にプログラムが書き込まれる. 

### pcとkv260をuartで接続する

以下のようにすると,改行がうまく行く.
```
picocom -b 115200 --imap lfcrlf /dev/ttyUSB2
```


## kv260でのqspiへの書き込み
```
bootgen -arch zynqmp -image qspi_boot.bif -o BOOT.BIN -w on
```
を実行して,webuiからkv260に入って書き込む. 
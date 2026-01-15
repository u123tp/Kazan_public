#!/usr/bin/env python3
import re
import sys

# 使い方:
#   python3 extract_0x_lines.py in.txt > out.txt
#   cat in.txt | python3 extract_0x_lines.py > out.txt

pat = re.compile(r'^\s*0x[0-9a-fA-F]+:')

def main():
    
    fin = open("qemu-asm.log", "r", encoding="utf-8", errors="replace")
    fout = open("qemu-raw-asm.log", "w",encoding="utf-8")
    fout2 = open("qemu-addr.log","w")

    for line in fin:
        if pat.match(line):
            fout.write(line.rstrip()+"\n")
            addr = line.split()[0].rstrip(":")
            fout2.write(addr+"\n")
            

    fin.close()
    fout.close()
    fout2.close()

if __name__ == "__main__":
    main()

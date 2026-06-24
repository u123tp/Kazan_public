mkdir -p elf bin hex   # 念のため作成

for f in elf/*; do
  base=$(basename "$f")                    # ファイル名だけ取り出す

  # ELF -> 生バイナリ
  riscv64-unknown-elf-objcopy -O binary \
    "$f" "bin/$base.bin"

  # バイナリ -> 32bit毎に 1 行の hex
  hexdump -v -e '1/4 "%08x\n"' \
    "bin/$base.bin" > "hex/$base.hex"
done
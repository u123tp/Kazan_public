for elf in ./riscv-tests-elf/*; do
  # 拡張子を .elf → .bin に置き換え
  bin=./riscv-tests-bin/$(basename "${elf%.elf}.bin")
  # objcopy でバイナリ生成
  riscv64-unknown-elf-objcopy -O binary "$elf" "$bin"
done
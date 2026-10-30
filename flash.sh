#!/bin/bash
ELF="build/Debug/STM32WB55.elf"
PROG="/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer/STM32CubeProgrammer.app/Contents/MacOs/bin/STM32_Programmer_CLI"

if [ ! -f "$ELF" ]; then
    echo "❌ 找不到 $ELF，先编译一下"
    exit 1
fi

echo "🔌 连接 STLINK (SWD)..."
"$PROG" -c "port=SWD mode=UR" 2>&1 | grep -E "ST-Link|Target|ERROR"

echo ""
echo "📦 烧录 $ELF..."
"$PROG" -c "port=SWD mode=UR" -w "$ELF" -v -rst

echo ""
echo "✅ 烧录完成！"
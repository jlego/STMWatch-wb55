#!/bin/bash
ELF="build/Debug/STM32WB55.elf"
PROG="/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer/STM32CubeProgrammer.app/Contents/MacOs/bin/STM32_Programmer_CLI"

if [ ! -f "$ELF" ]; then
    echo "❌ 找不到 $ELF，先编译一下"
    exit 1
fi

echo "=========================================="
echo "🔬 STM32WB55 SWO 日志查看器 (OpenOCD)"
echo "=========================================="
echo ""
echo "💡 提示：此脚本会启动 OpenOCD 并输出 SWO 日志"
echo "💡 SWO 日志中 [MAIN] 开头的就是 printf 输出"
echo "💡 按 Ctrl+C 退出"
echo ""

openocd -f interface/stlink.cfg \
        -f target/stm32wbx.cfg \
        -c "init" \
        -c "tpiu config internal - uart off 32000000" \
        -c "itm port 0 on" \
        -c "program $ELF verify reset exit" 2>&1 &
OPENOCD_PID=$!

sleep 2
if kill -0 $OPENOCD_PID 2>/dev/null; then
    echo ""
    echo "✅ OpenOCD 已启动 (PID=$OPENOCD_PID)"
    echo "📊 SWO 日志将输出到此处..."
    echo ""
    wait $OPENOCD_PID
else
    echo "❌ OpenOCD 启动失败"
fi
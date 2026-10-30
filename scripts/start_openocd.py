import os, sys, subprocess, time

OPENOCD_BIN = '/Users/ronghuiyu/.espressif/tools/openocd-esp32/v0.12.0-esp32-20260831/openocd-esp32/bin/openocd'
SCRIPTS_DIR = '/Users/ronghuiyu/.espressif/tools/openocd-esp32/v0.12.0-esp32-20260831/openocd-esp32/share/openocd/scripts'
PID_FILE = '/tmp/openocd.pid'

try:
    with open(PID_FILE) as f:
        old_pid = int(f.read().strip())
    os.kill(old_pid, 9)
    time.sleep(0.5)
except Exception:
    pass

pid = os.fork()
if pid > 0:
    sys.exit(0)

os.setsid()
os.umask(0)

pid2 = os.fork()
if pid2 > 0:
    sys.exit(0)

with open('/tmp/openocd.log', 'w') as f:
    os.dup2(f.fileno(), 1)
    os.dup2(f.fileno(), 2)

os.chdir(SCRIPTS_DIR)
with open(PID_FILE, 'w') as f:
    f.write(str(os.getpid()))

os.execv(OPENOCD_BIN, [OPENOCD_BIN, '-f', 'interface/stlink.cfg', '-f', 'target/stm32wbx.cfg'])
target remote localhost:2000

set print asm-demangle on

set backtrace limit 32

define lpc
	x/20i ($pc - 10)
end

monitor erase
load build/main
file build/main
monitor reset
stepi

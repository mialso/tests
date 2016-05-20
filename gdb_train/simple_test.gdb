#  gdb command file

break sum
commands 1

if one == 1
	continue
else
	echo "\nerror\n"
	quit
end
end

run
echo "\nsuccess\n"
quit

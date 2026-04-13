cmd_/home/dendrog/develop/kernel/hello-1/modules.order := {   echo /home/dendrog/develop/kernel/hello-1/hello-1.ko; :; } | awk '!x[$$0]++' - > /home/dendrog/develop/kernel/hello-1/modules.order

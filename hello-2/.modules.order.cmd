cmd_/home/dendrog/develop/kernel/hello-2/modules.order := {   echo /home/dendrog/develop/kernel/hello-2/hello-2.ko; :; } | awk '!x[$$0]++' - > /home/dendrog/develop/kernel/hello-2/modules.order

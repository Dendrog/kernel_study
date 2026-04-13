 /*
  * hello-2.c - module_init() 및 module_exit() 매크로 데모.
  * 이 방법은 init_module() 및 cleanup_module()을 사용하는 것보다 선호됩니다.
  */
 #include <linux/init.h> /* 매크로에 필요 */
 #include <linux/module.h> /* 모든 모듈에 필요 */
 #include <linux/printk.h> /* pr_info()에 필요 */

 static int __init hello_2_init(void)
 {
     pr_info("Hello, world 2\n");
     return 0;
 }

 static void __exit hello_2_exit(void)
 {
     pr_info("Goodbye, world 2\n");
 }

 module_init(hello_2_init);
 module_exit(hello_2_exit);

 MODULE_LICENSE("GPL");

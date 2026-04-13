 /*
  * hello-4.c - 모듈 문서 시연.
  */
 #include <linux/init.h> /* 매크로에 필요 */
 #include <linux/module.h> /* 모든 모듈에 필요 */
 #include <linux/printk.h> /* pr_info()에 필요 */

 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("LKMPG");
 MODULE_DESCRIPTION("A sample driver");

 static int __init init_hello_4(void)
 {
     pr_info("Hello, world 4\n");
     return 0;
 }

 static void __exit cleanup_hello_4(void)
 {
     pr_info("Goodbye, world 4\n");
 }

 module_init(init_hello_4);
 module_exit(cleanup_hello_4);

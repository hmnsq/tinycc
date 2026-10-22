/* Various things I encountered while hacking the pre processor */
#నిర్వచించు wrap(x) x
#నిర్వచించు pr_warning(fmt, ...) printk(KERN_WARNING fmt, ##__VA_ARGS__)
#నిర్వచించు pr_warn(x,y) pr_warning(x,y)
#నిర్వచించు net_ratelimited_function(function, ...) function(__VA_ARGS__)
X1 net_ratelimited_function(pr_warn, "pipapo", bla);
X2 net_ratelimited_function(wrap(pr_warn), "bla", foo);
#నిర్వచించు two m n
#నిర్వచించు chain4(a,b,c,d) a ## b ## c ## d
X2 chain4(two,o,p,q)
X3 chain4(o,two,p,q)
X4 chain4(o,p,two,q)
X5 chain4(o,p,q,two)

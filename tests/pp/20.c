/* Various things I encountered while hacking the pre processor */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wrap(x) x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ pr_warning(fmt, ...) printk(KERN_WARNING fmt, ##__VA_ARGS__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ pr_warn(x,y) pr_warning(x,y)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ net_ratelimited_function(function, ...) function(__VA_ARGS__)
X1 net_ratelimited_function(pr_warn, "pipapo", bla);
X2 net_ratelimited_function(wrap(pr_warn), "bla", foo);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ two m n
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ chain4(a,b,c,d) a ## b ## c ## d
X2 chain4(two,o,p,q)
X3 chain4(o,two,p,q)
X4 chain4(o,p,two,q)
X5 chain4(o,p,q,two)

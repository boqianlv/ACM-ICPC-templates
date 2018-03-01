## 算法一（针对测试点1）

我们可以暴力地维护锅所有锅内的食物，并暴力查询即可。

时间复杂度：$O\left( \left( n+Q\right)Q\right)$或$O\left( \left( n+Q\right)Q\log{n}\right)$

期望得分：8分

## 一些想法

我们可以分别维护锅内（未熟）的食物和锅外（已熟）的食物。对于操作$1,3$和操作$2$的第一部分（判定是否有已熟的食物），我们可以在锅外查询；对于操作$2$的第二部分（求最近的熟食），我们可以在锅内查询。


## 算法二（针对测试点1-3）

对于锅内的每种食物，我们分别使用链表（或vector）维护，这样操作$2$查询和操作$0$插入的操作**总**复杂度是$O\left( Q\right)$。

对于锅内食物熟了的时间，我们发现对于每种食物，食物煮熟的顺序和食物被放入的顺序是相同的，于是我们每次事件前暴力维护每个链表即可。总复杂度为$O\left( nQ\right)$。

对于锅外的食物，我们用数组（即$n$个变量）维护。于是对于每种操作$2$的第二部分查询，我们可以用$O\left( 1\right)$的时间回答；对于操作$1,3$的查询，我们可以用$O\left( n\right)$的时间回答。

于是我们即可在$O\left( nQ\right)$的时间复杂度内完成此题。

期望得分：20分

## 算法三（针对测试点4-5）

我们发现每个食物的$s$值均为$1$，也就是说在其被放入锅内后一个时刻即会被煮熟。而题目保证每一时刻最多只有一个事件，因此我们可以认为锅内没有食物。

于是我们只需要用树状数组维护锅外的食物，并支持树状数组上二分，即可轻松解决此题。（当然，我们也可以借助set，不过这可能会使你的程序有更大的常数）

时间复杂度：$O\left( Q\log{n}\right)$
期望得分：16分

## 算法四（针对测试点4-7）

对于锅内，我们可以使用链表（或vector）维护；对于锅外，我们可以用树状数组维护。

由于所有食物$s$值相同，所以所有食物被煮熟的顺序与它们被放入锅内的顺序一致，我们可以用指针维护下一个将要被煮熟的食物的位置，即可快速完成“从锅内到锅外”的操作。

时间复杂度：$O\left( Qlog{n}\right)$

期望得分：38分

## 算法五（针对测试点8-9）

我们发现不存在区间求和操作，于是我们同样适用链表（或vector）维护锅内，用multiset或map维护锅外即可。（这两个数据结构完美支持所有查询、修改操作）

对于食物被煮熟的顺序，我们可以额外使用一个priority_queue或堆来维护锅内的食物，其中关键字为食物被煮熟的时间。每次操作前，我们不断弹出堆顶，直到堆顶还未被煮熟为止，并将被弹出的食物加入锅外即可。

我们也可以将所有操作$t 0 id$拆分成$2$个操作：
1. $t$时刻将食物$id$加入锅内。
2. $t+s[id]$时刻将食物$id$从锅内取出，并加入锅外。

并将所有操作重新按时间顺序排序，然后依次执行。

时间复杂度：$O\left( Qlog{n+Q}\right)$

期望得分：14分

## 算法六（针对所有测试点）

结合算法五和支持二分功能的树状数组即是这道题目的标算。

时间复杂度：$O\left( Qlog{n+Q}\right)$

期望得分：100分

## 针对程序常数的说明

对于使用支持二分功能的树状数组、priority_queue以及multiset或map的程序，在实际运行速度上有着一些不同。这是因为前两个数据结构的常数远小于后二者。对于使用其他数据结构的程序，有可能同样会有不同程度的常数问题，选手也因此会得到$96-100$的分数（即有可能无法通过最后两个测试点）。

在实际测试中，上面提到的四种数据结构都可以获得$100$分。
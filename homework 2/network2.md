# Report

对于无向图的网络流建图，可以直接把两个方向的剩余容量都赋为这条无向边的容量，这样当一条边流过 $f$ 的流量时，正向剩余容量减去 $f$、反向剩余流量加上 $f$ 即可。

用Dinic算法求网络流图中 $s$ 到 $t$ 的最大流，时间复杂度 $O(n^2m)$。
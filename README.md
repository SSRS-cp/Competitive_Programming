# Data Structures
## UnionFind
UnionFind木 (経路圧縮のみ) です。

```C++
int unionfind_root(vector<int> &parent, int x)
```
UnionFind木parentの頂点xの根を求めます。

```C++
bool unionfind_unite(vector<int> &parent, int x, int y)
```
UnionFind木parentの頂点xと頂点yの属するグループを併合します。頂点xと頂点yが同じグループに属していた場合trueを、そうでない場合はfalseを返します。

## UnionFind 2
UnionFind木 (経路圧縮+rank)です。

## Segment Tree
セグメント木でRange Minimum Queryを行います。

```C++
vector<int> segtree(vector<int> &A)
```
配列Aからセグメント木を構築します。

```C++
void segtree_update(vector<int> &ST, int i, int x)
```
セグメント木STのA[i]にあたる要素をxに更新します。

```C++
int segtree_query(vector<int> &ST, int x, int y, int i, int L, int R)
```
セグメント木STの[x,y)区間に対するクエリの結果を、区間[L,R)に対応するセグメント木STの要素iが求めます。

# Graph
## Single Source Shortest Path (Dijkstra)
ダイクストラ法を利用して、単一始点最短路の長さを求めます。

```C++
vector<long long> dijkstra(vector<vector<pair<int, int>>> &E, int s)
```
重み付きグラフEの頂点sを始点とする単一始点最短路を求めます。頂点sから到達できない頂点に対してはINFを返します。

## Single Source Shortest Path (Bellman Ford)
ベルマンフォード法を利用して、単一始点最短路の長さを求めます。

```C++
vector<long long> bellman_ford(vector<vector<pair<int, int>>> &E, int s)
```
重み付きグラフEの頂点sを始点とする単一始点最短路を求めます。頂点sから到達できない頂点にはINFを返します。

```C++
bool detect_negative_cycles(vector<vector<pair<int, int>>> &E, int s)
```
重み付きグラフEに、頂点sから到達可能な負の閉路が存在するかを求めます。存在する場合はtrue、存在しない場合はfalseを返します。

```C++
bool detect_negative_cycles_2(vector<vector<pair<int, int>>> &E)
```
重み付きグラフEに、負の閉路が存在するかを求めます。

```C++
vector<bool> find_negative_cycles(vector<vector<pair<int, int>>> &E)
```
重み付きグラフEのすべての負の閉路を検出します。負の閉路に含まれる頂点に対してはtrue、そうでない頂点に対してはfalseを返します。

## All Pairs Shortest Path (Warshall Floyd)
ワーシャルフロイド法を利用して、全点対間最短路の長さを求めます。

```C++
vector<vector<long long>> warshall_floyd(vector<vector<pair<int, int>>> &E)
```
重み付きグラフEの全点対間最短路の長さを求めます。頂点sから頂点tに到達できない場合、その頂点対に対応する要素に対してはINFを返します。

## Convert to Rooted Tree
木を根付き木に変換します。

```C++
vector<int> parent(vector<vector<int>> &E, int r)
```
木Eを、頂点rを根とする根付き木に変換したときの、各頂点の親を求めます。

```C++
vector<vector<int>> child(vector<vector<int>> E, int r)
```
木Eを、頂点rを根とする根付き木に変換したときの、各頂点の子を求めます。

```C++
vector<vector<int>> child(vector<int> &p, int r)
```
頂点iの親がp[i]であり頂点rが根である根付き木の、各頂点の子を求めます。

## Rerooting 1
全方位木DPを行います。関数add、root、subが定義されている必要があります。頂点iに対する答えはroot(dp[i])となります。

## Rerooting 2
全方位木DPを行います。関数add、rootが定義されている必要があります。頂点iに対する答えはroot(add(dp1[i], dp2[i]))となります。


# Dynamic Programming
## Longest Common Subsequence
動的計画法を利用して、最長共通部分列を求めます。

```C++
int longest_common_subsequence_length(string &S, string &T)
```
文字列Sと文字列Tの最長共通部分列の長さを求めます。

```C++
string longest_common_subsequence(string &S, string &T)
```
文字列Sと文字列Tの最長共通部分列を求めます。

```C++
int longest_common_subsequence_length(vector<int> &A, vector<int> &B)
```
配列Aと配列Bの最長共通部分列の長さを求めます。

```C++
vector<int> longest_common_subsequence(vector<int> &A, vector<int> &B)
```
配列Aと配列Bの最長共通部分列を求めます。

## Longest Increasing Subsequence
動的計画法を利用して、最長増加部分列を求めます。

```C++
int longest_increasing_subsequence_length(vector<int> &A)
```
配列Aの最長増加部分列の長さを求めます。

## Matrix Chain Multiplication
動的計画法を利用して、連鎖行列積問題を解きます。

```C++
long long matrix_chain_multiplication(vector<long long> &A)
```
行列M_0, M_1, ..., M_{n-2}があり、M_iがA_i×A_{i+1}行列である(0≦i≦n-1)とき、積M_0M_1...M_{n-2}を計算するのに必要なスカラーの乗算回数の最小値を求めます。

# Math
## Modulo
MODで割った余りを扱います。MODの値はグローバル変数として与えられる必要があります。MODは素数である必要があります。

```C++
long long modsub(long long a, long long b)
```
a-bをMODで割った余りを求めます。aとbは非負整数である必要があります。

```C++
long long modpow(long long a, long long b)
```
二分累乗法を利用して、aのb乗をMODで割った余りを求めます。

```C++
long long modinv(long long a)
```
aの逆元を求めます。

```C++
long long modfact(long long n)
```
nの階乗をMODで割った余りを求めます。値は配列mfに記録され、再利用されます。

```C++
long long modbinom1(long long n, long long r)
```
二項係数nCrをMODで割った余りを求めます。それぞれのクエリに対しO(1)で値を返しますが、O(n)の前計算が必要になります。

```C++
long long modbinom2(long long n, long long r)
```
二項係数nCrをMODで割った余りを求めます。nが大きくても計算できますが、それぞれのクエリに対しO(r)の時間が必要になります。

## Catalan Number
カタラン数を求めます。

```C++
long long catalan_number(long long n)
```
カタラン数C_nをMODで割った余りを求めます。

## Prime
素数や素因数分解を扱います。

```C++
bool is_prime(long long N)
```
2以上の整数Nが素数かどうか判定します。Nが素数である場合trueを、そうでない場合falseを返します。

```C++
vector<long long> prime_factorizarion(long long N)
```
Nを素因数分解します。

```C++
int factor_count(long long N)
```
Nの正の約数の個数を求めます。

## Cycle Decomposition
置換を巡回置換に分解します。

```C++
vector<vector<int>> cycle_decomposition(vector<int> &P)
```
置換Pを巡回置換に分解します。それぞれの置換では最も大きい数が先頭になります。置換は先頭の数が大きい順に返されます。

# Geometry
## Point
点を扱います。

```C++
int sign(double x)
```
EPSを考慮して、xの符号を返します。xが正のとき1を、負のとき-1を、0のとき0を返します。

```C++
bool equals(double x, double y)
```
EPSを考慮して、xとyが等しいかどうかを調べます。

```C++
point()
```
コンストラクタです。引数に何も指定しない場合、点は原点(0,0)となります。

```C++
point(double X, double Y)
```
コンストラクタです。引数がXとYであるとき、点は点(X,Y)となります。

```C++
point operator +()
```
正号です。+(x,y)=(x,y)となります。

```C++
point operator -()
```
負号です。-(x,y)=(-x,-y)となります。

```C++
point operator +(point P)
```
点と点を加えます。(x1,y1)+(x2,y2)=(x1+x2,y1+y2)となります。

```C++
point operator -(point P)
```
点と点の差を求めます。(x1,y1)+(x2,y2)=(x1-x2,y1-y2)となります。

```C++
point& operator +=(point P)
```
点に点を加え、結果を代入します。

```C++
point& operator -=(point P)
```
点から点を引き、結果を代入します。

```C++
point operator *(double k)
```
点を定数倍します。(x,y)* k=(kx,ky)となります。

```C++
point operator /(double k)
```
点を定数で割ります。(x,y)/k=(x/k,y/k)となります。

```C++
point& operator *=(double k)
```
点を定数倍し、結果を代入します。

```C++
point& operator /=(double k)
```
点を定数で割り、結果を代入します。

```C++
bool operator ==(point P)
```
EPSを考慮して、2つの点が同じ点であるかを調べます。

```C++
bool operator !=(point P)
```
2つの点が異なる点であるかを調べます。

```C++
bool operator <(point P)
```
2つの点を比較します。x座標が大きいほうが大きい点で、x座標が等しい場合y座標が大きいほうが大きい点となります。

```C++
bool operator >(point P)
```
2つの点を比較します。

```C++
point& rotate(double t)
```
点を原点を中心としてtラジアン回転させます。

```C++
point& rotate(point P, double t)
```
点を点Pを中心としてtラジアン回転させます。

```C++
point& rotate90(point P)
```
点を原点を中心として90°(π/4ラジアン)回転させます。

```C++
istream& operator >>(istream &is, point &P)
```
点のx座標とy座標を入力から受け取ります。

```C++
ostream& operator <<(ostream &os, point p)
```
点のx座標とy座標をスペース区切りで出力します。

```C++
point rotate(point P, double t)
```
点Pを原点を中心としてtラジアン回転させた後の点を求めます。

```C++
point rotate(point P, point Q, double t)
```
点Pを点Qを中心としてtラジアン回転させた後の点を求めます。

```C++
point rotate90(point P)
```
点Pを原点を中心として90°(π/4ラジアン)回転させます。

```C++
point midpoint(point P, point Q)
```
点Pと点Qの中点を求めます。

```C++
double dot(point P, point Q)
```
点Pと点Qの内積P·Qを求めます。(x1,y1)·(x2,y2)=x1x2+y1y2となります。

```C++
double cross(point P, point Q)
```
点Pと点Qの外積P×Qを求めます。(x1,y1)×(x2,y2)=x1y2-x2y1となります。

```C++
double arg(point P)
```
点Pの偏角を求めます。

```C++
int ccw(point P, point Q, point R)
```
点P,Qに対する点Rの位置を求めます。点Rが線分PQの左側にあるとき1、右側にあるとき-1、後側にあるとき-2、前側にあるとき2、線分PQ上にあるとき0を返します。

## Line
直線・半直線・線分を扱います。

```C++
line()
```
コンストラクタです。

```C++
line(point P)
```
コンストラクタです。原点と点Pを通る直線を作ります。
```C++
line(point P, point Q)
```
コンストラクタです。2点P,Qを通る直線を作ります。

```C++
line(double a, double b)
```
コンストラクタです。直線y=ax+bを作ります。

```C++
line(double a, double b, double c)
```
コンストラクタです。直線ax+by+c=0を作ります。

```C++
bool operator ==(line L)
```
2つの直線が同一の直線を表すか判定します。

```C++
bool operator !=(line L)
```
2つの直線が異なる直線を表すか判定します。

```C++
bool operator <(line L)
```
2つの直線を比較します。始点が大きいほうが大きい直線で、始点が等しい場合終点が大きいほうが大きい直線となります。

```C++
bool operator >(line L)
```
2つの直線を比較します。

```C++
istream& operator >>(istream &is, point &P)
```
直線を入力から受け取ります。

```C++
ostream& operator <<(ostream &os, point p)
```
直線を出力します。

```C++
point vec(line L)
```
ベクトルAB→を返します。

```C++
point projection(point P, line L)
```
点Pから直線Lに下ろした垂線の足を求めます。

```C++
point reflection(point P, line L)
```
直線Lについて点Pと対称な点を求めます。

```C++
line perpendicular_line(point P, line L)
```
点Pから直線Lに垂線を下ろします。

```C++
bool is_orthogonal(line a, line b)
```
2直線a, bが直交するか判定します。

```C++
bool is_parallel(line a, line b)
```
2直線a, bが平行であるか判定します。2直線a, bが同じ直線を表す場合、平行であると判定されます。

```C++
bool is_on_line(point P, line L)
```
点Pが直線L上にあるか判定します。

```C++
bool is_on_segment(point P, segment L)
```
点Pが線分L上にあるか判定します。

```C++
bool is_intersecting_line(line a, line b)
```
2直線a, bが交点を持つか判定します。2直線a, bが同じ直線を表す場合、交点を持たないと判定されます。

```C++
pair<bool, point> line_intersection(line L1, line L2)
```
2直線L1, L2の共有点を求めます。2直線L1, L2が共有点を持つ場合、第1要素にtrue、第2要素に共有点の座標が入ります。そうでない場合、第1要素にfalseが入ります。

```C++
pair<bool, point> segment_intersection(segment S1, segment S2)
```
2線分S1, S2の共有点を求めます。2直線S1, S2が共有点を持つ場合、第1要素にtrue、第2要素に共有点の座標が入ります。そうでない場合、第1要素にfalseが入ります。

template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(int n, function<T(T, T)> F, T e){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, e);
		f = F;
		E = e;
	}
	segment_tree(vector<T> A, function<T(T, T)> F, T e){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, e);
		f = F;
		E = e;
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T operator [](int k){
		return ST[N - 1 + k];
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T val(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return E;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return f(val(L, R, i * 2 + 1, l, m), val(L, R, i * 2 + 2, m, r));
		}
	}
	T query(int L, int R){
		return val(L, R, 0, 0, N);
	}
};

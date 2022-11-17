void data_yang(int n, int data[n][n],
		void(*p)(int n, int(*p)[n]),
		void(*out)(int, int(*p)[n]))
{
	p(n, data);
	out(n, data);
}


void data_sort (int data[], int n,
	void(*p)(int* p, int n), void(*out)(int*, int))
{
	/*通过函数指针p去调用不同的实现排序算法的回调函数*/
	p(data, n);
	/*通过函数指针out调用输出数组元素的回调函数*/
	out(data, n);
}

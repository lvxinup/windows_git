#define  _CRT_SECURE_NO_WARNINGS 1

/*二进制加法。发现一个特点。
位的异或运算跟求'和'的结果一致：
异或 1^1=0 1^0=1 0^0=0
求和 1+1=0 1+0=1 0+0=0
位的与运算跟求'进位‘的结果一致：
位与 1&1=1 1&0=0 0&0=0
进位 1+1=1 1+0=0 0+0=0
于是可以用异或运算和与运算来表示加法*/
class UnusualAdd {
public:
	int addAB(int A, int B) {

		int a, b;
		while (B != 0)
		{
			a = A^B;
			b = (A&B) << 1;
			A = a;
			B = b;
		}
		return A;
	}
};
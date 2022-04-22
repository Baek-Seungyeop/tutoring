#include<stdio.h>
#include<math.h>

/*
	2022년 4월 8일 튜터링 요약 : 프로그래밍 작성과정, 변수와 자료형

	비주얼 스튜디오는 개발자를 위해 만들어진 툴
	우리가 코딩한 소스코드를 어떻게 알아보는가? : 컴파일을 통해 알아본다.

	컴파일 과정 : 전처리기(#으로 시작하는 것을 읽어 불러오는 작업) -> 컴파일러(고급언어를 저급언어로) -> 어셈블러(기계어로) -> 링커(프로그램을 묶는 작업)
	ASCODE에 commit(컴파일)할려고 소스코드를 올렸는데 에러가 나온다.
	크게 두 가지로 볼 수 있는데 
	1. 컴파일 에러(문법 오류, ';', '&'안 붙이는 등 문법을 안 지켰을 때의 오류)
	2. 런타임 에러(무한 루프, 예를 들면, 반복문의 끝나는 조건을 만족하지 않아 프로그램이 끝나지 않는 오류)

	int main(), void main() 과 return 0; 는 무엇 일까?
	전자는 (운영체제한테) 우리가 작성한 소스코드가 여기 있임을 알리는 구문
	후자는 (운영체제한테) 프로그램이 끝났음을 알리는 구문

	변수 자료형
	정수형 : int(d), short, long(ld), long long(lld)
	실수형(부동 소수점) : float(f), double(lf)
	문자형 : char(int와 같다, c), string(s)

	scanf, printf할 때 서식을 지켜줘야한다. 
	시험에서는 우교수님 문제 스타일 상 
	scanf는 ("%d %d", &x, &y); 한 칸씩 띄어서 입력
	printf는 ("%d %d\n", x, y); 한 칸씩 띄어서 출력하되 테스트 케이스당 한 줄로 출력
	으로 내실 확률이 매우 크다.

	2022년 4월 8일 튜터링 피드백(튜티들이 헷갈려 했던 부분 보충) :
	C언어는 위에서 아래로 읽는 절차식 언어이다.(매우 중요, 나중에 함수 선언할 때도 함수 선언 순서에 따라 오류가 날 수 있고 정상적으로 돌아갈 수 있음)
	그리고 변수선언을 하는 것은 컴퓨터에서 나 변수를 만들고 싶은데 자료형은 int형이야 메모리 잡아줘라고 말하는 것과 동일하다.
	따라서, 변수를 쓰고 싶을 때 자신이 선언을 하였는지 위치가 맞는지 확인해보자.

	2022년 4월 8일 튜터링 추가내용(알아두면 좋은 것, 무조건 이런 실수하게 되어있다.) :
	double i = 1.0 / 3.0; 
	double j = 1.0f / 3.0f;
	float k = 1.0f / 3.0f;
	한 번씩 출력해보고 값이 다르게 나온다면 왜 다르게 나오는지 한 번 생각해볼 것.
*/

/*
	2022년 4월 15일 튜터링 내용 : 수식과 연산자 그리고, 제어문

	산술연산자 : +, -, *, /, % (더하기, 빼기, 곱하기, 나누기, 나머지)

	전위 연산자 : i++ (수행 후 증가)
	int x = 3;
	int y = x++;
	printf("%d %d\n", y, x);

	후위 연산자 : ++i (증가 후 수행)
	int i = 3;
	int j = ++i;
	printf("%d\n", j);

	논리 연산자 : 
	A && B (논리곱, A, B 모두 참일 때 참 그렇지 않으면 거짓)
	A || B (논리합, A, B 하나라도 참이면 참 그렇지 않으면 거짓)
	!A (논리부정, A가 참이면 거짓, 거짓이면 참)

	비트 연산자 :
	& (비트곱, 비트 값이 둘 다 1일 때만 1, 그렇지 않으면 0)
	| (비트합, 비트 값이 하나라도 1이면 1, 그렇지 않으면 0)
	^ (베타적 비트합, 비트 값이 서로 다를 때만 1, 그렇지 않으면 0)
	~ (NOT, 비트 값이 1이면 0, 0이면 1)

	제어문 : if와 switch
	if(논리) : 논리가 0이면 거짓(실행 안 함), 0이 아니면 참(실행)
	else if(논리) : 단독으로 쓸 수 없음에 유의, 위의 if문이 실행 안 되었을 때 추가적인 제어문을 하고 싶을 때 사용
	else : 단독으로 쓸 수 없음에 유의, 위의 모든 if, else if의 조건을 만족하지 않을 때 작업이 필요하면 사용

	switch(조건식) {
		case 10 : 
			내용
			break;
		case 9 :
			내용
			break;
		default :
			내용;
			break;(생략가능)
	}
	switch는 위에서 아래로 가는(끝까지 수행하는) 제어문이기에 특정 값을 수행 후 밑에 것을 수행하고 싶지 않다면 break;로 탈출 해줘야한다.
	마지막에 default문은 모든 case비교 후 해당하는 case가 없을 때 수행할 것이 있다면 작성해준다.
	default의 break;는 어짜피 마지막에 수행되는 것이기에 생략해도 상괍없다.

	2022년 4월 15일 튜터링 주의점 : if(), esle if(), switch() 안에는 논리 판단이 가능한 값이 들어가야한다. (값 또는 '==', '||' 연산자) (대입 연산자인 '='은 불가능)

	2022년 4월 15일 튜터링 추가내용(까먹어도 좋으나 기억해두면 이해하기 도움되는 내용) : 나중에 배우는 반복문 for 그리고 이번에 배운 if, else if, else는 뒤에 오는 content(내용)이 한 줄이라면 중괄호를 생략 가능하다.
	
	또한, 우리가 배우는 문법은 C이다. 나중에 C#, C++, java, python 등. 다른 언어를 2, 3, 4학년 때 듣게 될 것이다.
	내가 지금 배우고 있는 C#, C++은 C의 개념만 확실히 알고있다면 달라진 문법만 잡으면 쓰는데 부담이 없는 수준이다. (그 만큼 C의 문법과 개념이 중요하다.)
	그리고 python은 3학년 친구들한테 듣길 C의 들여쓰기 방식을 문법으로 만들었기 때문에 그만큼 C의 코딩스타일을 확실히 잡아야 유리하다는 것을 알수 있겠지?  

	2022년 4월 22일 튜터링 내용 : 

	튜티들이 풀다가 질문했던 문제를 풀어서 알려주었다.
	ascode.org -> 대회 -> 2022학년도 1학기 프로그래밍실습 중간고사 대비용에서의 F, G, H에 대해 알아보자.

	F문제 : 문자 쌍 출력하기

const int CONVERT = 32; // 대문자 <-> 소문자

int main() 
{
	int testcase, ascii1, ascii2;
	bool upper1, upper2, lower1, lower2, isalphabet1, isalphabet2;

	scanf("%d", &testcase);

	while (testcase--)
	{
		scanf("%d %d", &ascii1, &ascii2);

		upper1 = (ascii1 >= 'A' && ascii1 <= 'Z');
		lower1 = (ascii1 >= 'a' && ascii1 <= 'z');
		upper2 = (ascii2 >= 'A' && ascii2 <= 'Z');
		lower2 = (ascii2 >= 'a' && ascii2 <= 'z');

		isalphabet1 = (upper1 || lower1);
		isalphabet2 = (upper2 || lower2);

		if (isalphabet1 && isalphabet2)
		{
			if (upper1 && upper2)
			{
				ascii1 += CONVERT;
				ascii2 += CONVERT;
			}
			else if (lower1 && lower2)
			{
				ascii1 -= CONVERT;
				ascii2 -= CONVERT;
			}
			printf("%c%c\n", ascii1, ascii2);
		}
		else printf("No Alphabet!\n");
	}
	return 0;
}

	문제 G : 로또 추천 번호 판정하기

int main() 
{
	int num1, num2, num3, num4, num5, num6, sum, count, odd;

	scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6);

	odd = count = 0;
	sum = num1 + num2 + num3 + num4 + num5 + num6;

	if (num1 % 2 == 1) odd++;
	if (num2 % 2 == 1) odd++;
	if (num3 % 2 == 1) odd++;
	if (num4 % 2 == 1) odd++;
	if (num5 % 2 == 1) odd++;
	if (num6 % 2 == 1) odd++;

	if (sum >= 91 && sum <= 180) count++;
	if (odd >= 2 && odd <= 4)count++;

	if (count == 2) printf("BEST");
	else if (count == 1)printf("GOOD");
	else printf("BAD");

	return 0;
}

	문제 H : 2차 방정식 근의 판별
int main()
{
	double a, b, c, valueN, value, bigvalue, smallvalue;

	scanf("%lf %lf %lf", &a, &b, &c);

	valueN = b * b - 4 * a * c;

	if (valueN < 0) printf("imaginary");

	else
	{
		if (valueN == 0)
		{
			value = -b / (2 * a);

			printf("%.4lf", value);
		}
		else
		{
			value = sqrt(valueN);
			bigvalue = (-b + value) / (2 * a);
			smallvalue = (-b - value) / (2 * a);

			printf("%.4lf %.4lf", bigvalue, smallvalue);
		}
	}
	return 0;
}

	2022년 4월 22일 튜터링 요약 : 위 코드처럼 남들이 봤을 때 바로 이해되게 하는 것이 나중을 위해 중요하다.
	위 처럼 만들러면 1. 최대한 용도에 맞는 변수명 2. 그냥 상수항을 더하는게 아닌 
	'변수 + 변수'처럼 자신이 무엇을 더하는지를 확실히 알 수 있게 짜는 것.
	3. 예를 들어, if(논리)에서 논리 값 또한 상수항을 넣는 것이 아닌 무엇에 대한 참, 거짓을 알고 싶은 건지 명시하는 것.
*/

/*
	잔소리 : 
	테스트 케이스의 모두 고려하자. 맞왜틀?(맞는데 왜 틀림?) 컴퓨터는 안 틀린다 너가 틀린거다 ㅋㅋ.
	모든 테이트케이스에서 가장 중요한 것은 최댓값, 최솟값, 아무 특정값 1개 (+변수가 0일 때)이다. (매우 중요)
	입력, 출력에 관한 확실한 해석 후 문제를 풀 것!
*/

int main()
{
	// 다들 시험 파이팅~~

}
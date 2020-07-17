

import java.util.EmptyStackException;
import java.util.Scanner;
import java.util.Stack;

public class 스택10828 {

	public static void main(String[] args) {
		// 스택과 스캐너 생성
		Stack<Integer> stack = new Stack<Integer>();
		Scanner scanner = new Scanner(System.in);
		
		// tc 입력 받기
		int tc = scanner.nextInt();
		scanner.nextLine();
		
		// tc만큼 반복
		for (int i = 0; i < tc; i++) {
			// 입력
			String str = scanner.nextLine();
			
			// 명령문을 스택에 실행한다.
			switch (str) {
			case "size":
				System.out.println(stack.size());
				break;
			case "empty":
				if (stack.isEmpty()) {
					System.out.println(1);
				} else {
					System.out.println(0);
				}
				break;
			case "top":
				try {
					System.out.println(stack.peek());
				} catch (EmptyStackException e) {
					System.out.println(-1);
				}
				break;
			case "pop":
				try {
					System.out.println(stack.pop());
				} catch (EmptyStackException e) {
					System.out.println(-1);
				}
				break;
			default:
				int num = Integer.parseInt((str.substring(5)));
				stack.push(num);
				break;
			}
		}
	}

}

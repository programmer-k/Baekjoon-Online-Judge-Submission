

import java.util.EmptyStackException;
import java.util.Scanner;
import java.util.Stack;

public class ����10828 {

	public static void main(String[] args) {
		// ���ð� ��ĳ�� ����
		Stack<Integer> stack = new Stack<Integer>();
		Scanner scanner = new Scanner(System.in);
		
		// tc �Է� �ޱ�
		int tc = scanner.nextInt();
		scanner.nextLine();
		
		// tc��ŭ �ݺ�
		for (int i = 0; i < tc; i++) {
			// �Է�
			String str = scanner.nextLine();
			
			// ��ɹ��� ���ÿ� �����Ѵ�.
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

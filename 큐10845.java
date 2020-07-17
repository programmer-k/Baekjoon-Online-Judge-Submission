

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class 큐10845 {

	public static void main(String[] args) {
		Queue<Integer> queue = new LinkedList<>();
		Scanner scanner = new Scanner(System.in);
		int lastNum = 0;
		int tc = scanner.nextInt();
		scanner.nextLine();		// \r\n을 없애기 위해
		
		for (int i = 0; i < tc; i++) {
			String str = scanner.nextLine();
			Integer ret = null;
			
			switch (str) {
			case "front":
				ret = queue.peek();
				if (ret == null) {
					System.out.println(-1);
				} else {
					System.out.println(ret);
				}
				break;
			case "back":
				if (queue.isEmpty()) {
					System.out.println(-1);
				} else {
					System.out.println(lastNum);
				}
				break;
			case "empty":
				if (queue.isEmpty()) {
					System.out.println(1);
				} else {
					System.out.println(0);
				}
				break;
			case "size":
				System.out.println(queue.size());
				break;
			case "pop":
				ret = queue.poll();
				if (ret == null) {
					System.out.println(-1);
				} else {
					System.out.println(ret);
				}
				break;
			default:
				lastNum = Integer.parseInt(str.substring(5));
				queue.add(lastNum);
			}
		}
	}

}

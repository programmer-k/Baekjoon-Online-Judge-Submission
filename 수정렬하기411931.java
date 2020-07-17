

//import java.io.BufferedReader;
//import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
// import java.util.Scanner;

public class 수정렬하기411931 {

	public static void main(String[] args) throws Exception {
		// 백준 문제 2750번 - 정렬하는 문제로 제대로 들어갔는지 확인해보기
		// 시간초과남. - 입출력을 바꿨는데도 그러는 걸 보니 아마 O(log n)이지만 순회하는데 시간이 오래걸릴 수 있음.
		// 이상하게 수 정렬하기 3은 맞는데, 수 정렬하기 2는 틀리네.. -> 맞았음 ㅋㅋㅋ 이게 case1, 3에서 약간의 문제가 생겨서 제대로 돌아가긴 하는데, 트리의 높이가 좀 커서 걸린 것 같음.
		// 수 정렬하기 1, 2, 3 이 코드로 다 통과함.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		RedBlackTree tree = new RedBlackTree();
		// Scanner scanner = new Scanner(System.in);
		
		int tc = Integer.parseInt(br.readLine());
		for (int i = 0; i < tc; i++) {
			int num = Integer.parseInt(br.readLine());
			tree.insert(num, Integer.toString(num));
			//System.out.println("Hello:" + tree.root.key + tree.root.parent);
		}
		
		tree.inorderTraversal(bw);
		// scanner.close();
		br.close();
		bw.close();
	}
}

// 이클립스에서 에러가 떠서 잠시 아래의 클래스 2개를 주석 처리 해놓았음.

/*class RedBlackNode {
	public boolean red;
	public int key;
	public String payload;
	public RedBlackNode parent;
	public RedBlackNode left, right;
	
	// 테스트를 위한 코드
	public int count = 1;
}*/





/*class RedBlackTree {
	public RedBlackNode root;
	
	public RedBlackTree() {
		// 루트가 없을 때는 null 값으로 표기
		root = null;
	}
	
	public boolean isEmpty() {
		if (root == null)
			return true;
		else
			return false;
	}
	
	public boolean hasLeftChild(RedBlackNode node) {
		if (node.left == null)
			return false;
		else
			return true;
	}
	
	public boolean hasRightChild(RedBlackNode node) {
		if (node.right == null)
			return false;
		else
			return true;
	}
	
	public boolean insert(int k, String p) {
		// 제일 간단한 case - RedBlackTree가 비었을 때,
		if (root == null) {
			root = new RedBlackNode();
			root.key = k;
			root.payload = p;
			root.left = null;	// RedBlackTree에서 insertion을 할 때, 제일 먼저 하는 것이 기존의 BinarySearchTree에서 하는 것처럼 root로부터 내려가는 것인데, 그렇다면 node의 left, right child는 null일 수밖에 없음.
			root.right = null;
			root.parent = null;
			root.red = false;
			return true;
		}
		
		// 삽입할 위치 찾기
		RedBlackNode prev = null;
		RedBlackNode cur = root;
		boolean left = false;
		while (cur != null) {
			if (cur.key < k) {
				prev = cur;
				cur = cur.left;
				left = true;
			} else if (cur.key > k) {
				prev = cur;
				cur = cur.right;
				left = false;
			} else {
				// k가 이미 존재하면, 아무것도 하지 않고 반환한다.
				// return false;
				

				// 테스트를 위한 코드
				cur.count++;
				return true;
			}
		}
		
		RedBlackNode x;
		
		// 연결하기
		if (left) {
			prev.left = new RedBlackNode();
			prev.left.key = k;
			prev.left.parent = prev;
			prev.left.payload = p;
			prev.left.red = true;
			prev.left.left = null;
			prev.left.right = null;
			x = prev.left;
		} else {
			prev.right = new RedBlackNode();
			prev.right.key = k;
			prev.right.parent = prev;
			prev.right.payload = p;
			prev.right.red = true;
			prev.right.left = null;
			prev.right.right = null;
			x = prev.right;
		}
		
		// System.out.println();
		//System.out.println("입력이 " + k);
		//System.out.println();
		
		while (x != root && x.parent.red) {
			if (x.parent == x.parent.parent.left) {
				// uncle이 null일수도 있음 -> NullPointerException을 방지하기 위한 코드 추가
				if (x.parent.parent.right != null && x.parent.parent.right.red) {
					x.parent.red = false;
					x.parent.parent.right.red = false;
					x.parent.parent.red = true;
					x = x.parent.parent;
					// System.out.println("case1");
					
				} else {
					if (x == x.parent.right) {
						x.parent.parent.left = x;
						RedBlackNode tempA = x.parent;
						x.parent = x.parent.parent;
						tempA.parent = x;
						tempA.right = x.left;
						x.left = tempA;
						if (tempA.right != null)
							tempA.right.parent = tempA;
						x = tempA;
						// System.out.println("case2!!");
					}
					// System.out.println("case3");
					x.parent.red = false;
					x.parent.parent.red = true;
					if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.right)		// 높이가 길 때 이부분을 실행, 높이가 짧을 때, root를 바꾸는 걸 실행
						x.parent.parent.parent.right = x.parent;
					else if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.left)
						x.parent.parent.parent.left = x.parent;
					RedBlackNode temp = x.parent.parent.parent;
					x.parent.parent.parent = x.parent;
					x.parent.parent.left = x.parent.right;
					x.parent.right = x.parent.parent;
					
					if (x.parent.right.left != null)
						x.parent.right.left.parent = x.parent.right;
					
					x.parent.parent = temp;
					x = root;
					
					// 5, 3, 2를 넣으면, root가 5를 가리키고 있기 때문에, 5만 출력이 되는 상황이 발생함. 그러므로 root를 바꿔줘야함.
					// 이 때, 바꿔준 root의 parent값을 null로 다시 설정해줘야함.
					if (root.parent != null) {
						root = root.parent;
						root.parent = null;
					}
				}
			} else {
				// 위의 코드에서 왼쪽의 경우와 똑같이 NullPointerException 발생할 수 있음. (uncle이 null일 경우)
				if (x.parent.parent.left != null && x.parent.parent.left.red) {
					x.parent.red = false;
					x.parent.parent.left.red = false;
					x.parent.parent.red = true;
					x = x.parent.parent;
					// System.out.println("case1");
					// inorderTraversal();
					// System.out.println(root.key);
					// System.out.println(root.parent);
				} else {
					if (x == x.parent.left) {
						x.parent.parent.right = x;
						RedBlackNode tempA = x.parent;
						x.parent = x.parent.parent;
						tempA.parent = x;
						tempA.left = x.right;
						x.right = tempA;
						if (tempA.left != null)
							tempA.left.parent = tempA;
						x = tempA;
						// System.out.println("case2!");
					}
					// System.out.println("case3 - !!");
					x.parent.red = false;
					x.parent.parent.red = true;
					// parent의 parent의 parent과 연결을 놓침.
					if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.left)		// 높이가 길 때 이부분을 실행, 높이가 짧을 때, root를 바꾸는 걸 실행
						x.parent.parent.parent.left = x.parent;
					else if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.right)
						x.parent.parent.parent.right = x.parent;
					RedBlackNode temp = x.parent.parent.parent;
					// System.out.println("temp:" + x.parent.parent.parent);
					x.parent.parent.parent = x.parent;
					x.parent.parent.right = x.parent.left;
					x.parent.left = x.parent.parent;
					
					if (x.parent.left.right != null)
						x.parent.left.right.parent = x.parent.left;
					
					x.parent.parent = temp;
					
					x = root;
					
					// 위와 같은 상황을 대비해서
					if (root.parent != null) {
						root = root.parent;
						root.parent = null;
					}
				}
			}
			// System.out.println(x.key);
		}
		root.red = false;
		
		
		// inorderTraversal();
		return true;
	}
	
	public String query(int k) {
		// 제일 간단한 case - RedBlackTree가 비었을 때,
		if (root == null) {
			return null;
		}
		
		// 삽입할 위치 찾기
		RedBlackNode prev = null;
		RedBlackNode cur = root;
		boolean left = false;
		while (cur != null) {
			if (cur.key > k) {
				prev = cur;
				cur = cur.left;
				left = true;
			} else if (cur.key < k) {
				prev = cur;
				cur = cur.right;
				left = false;
			} else {
				// k가 이미 존재하면, 아무것도 하지 않고 반환한다.
				return null;
			}
		}
		
		if (left) {
			return prev.left.payload;
		} else {
			return prev.right.payload;
		}
	}
	
	// 테스트를 위한 함수
	public void doInorderTraversal(RedBlackNode node, BufferedWriter bw) {
		if (node == null)
			return;
		try {
			doInorderTraversal(node.left, bw);
			for (int i = 0; i < node.count; i++) {
				bw.write(node.payload);
				bw.newLine();
				if (node.red)
					System.out.println("red");
				else
					System.out.println("black");
			}
			doInorderTraversal(node.right, bw);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	// 테스트를 위한 함수
	public void inorderTraversal(BufferedWriter bw) {
		doInorderTraversal(root, bw);
	}
}*/


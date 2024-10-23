 private static int maxXor(TrieNode head, int x) {
        int res = 0;
        for (int i = 59; i >= 0; i--) {
            if ((x & (1L << i)) != 0) {
                if (head.left != null) {
                    res += (1L << i);
                    head = head.left;
                } else {
                    head = head.right;
                }
            } else {
                if (head.right != null) {
                    res += (1L << i);
                    head = head.right;
                } else {
                    head = head.left;
                }
            }
        }
        return res;
    }
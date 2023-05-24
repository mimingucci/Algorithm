public static class Pair<F, SC> implements Comparable{
        public F First;
        public SC Second;

        public Pair(F first, SC second) {
            First = first;
            Second = second;
        }

        public F getFirst() {
            return First;
        }

        public void setFirst(F first) {
            First = first;
        }

        public SC getSecond() {
            return Second;
        }

        public void setSecond(SC second) {
            Second = second;
        }

        @Override
        public int compareTo(Object o) {
            if((int)this.getFirst()-(int)((Pair)o).getFirst()!=0)
            return (int)this.getFirst()-(int)((Pair)o).getFirst();
            else return (int)this.getSecond()-(int)((Pair)o).getSecond();
        }
    }


public static class HashTable{
        private static final int P=1000000+3;
        Vector<Pair<Integer, Integer>> h[]=new Vector[P];

        public HashTable() {
            for(int i=0; i<P; i++){
                h[i]=new Vector<Pair<Integer, Integer>>();
            }
        }

        private int getHash(int key){
            return key%P;
        }

        public void insert(int key, int value){
            int hKey=getHash(key);
            for(var x : h[hKey]){
                if(x.getFirst()==key){
                    return;
                }
            }
            h[hKey].add(new Pair<>(key, value));
        }

        public int find(int key){
            int hKey=getHash(key);
            for(var x : h[hKey]){
                if(x.getFirst()==key){
                   return x.getSecond();
                }
            }
            return 0;
        }
    }
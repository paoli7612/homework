class Contatore {
    private int val;

    public Contatore() {
        this.val = 0;
    }

    public void setVal(int val) {
        this.val = val;
    }

    public void inc() {
        this.val += 1;
    }

    public int getVal() {
        return this.val;
    }
}

class Quattro {
    public static void main(String[] args) {
        Contatore c = new Contatore();

        System.out.println(c.getVal());
        c.inc();
        System.out.println(c.getVal());
        c.inc(); c.inc(); c.inc();
        System.out.println(c.getVal());
    }
}
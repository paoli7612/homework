import java.sql.Date;

class Persona {
    private java.util.Date nascita = new Date(1, 1, 2000);
    private String nome;
    private String cognome;

    public Persona(String nome, String cognome) {
        this.nome = nome;
        this.cognome = cognome;
    }

    public void setNascita(Date nascita) {
        this.nascita = nascita;
    }

    public void stampa() {
        System.out.println(cognome + " " + nome);
        if (!nascita.equals(new Date(100, 1, 1)))
            System.out.println(nascita.toString());
    }
}

public class Main {
    public static void main(String[] args) {
        Persona p = new Persona("Tommaso", "Paoli");
        p.setNascita(new Date(100, 4, 21));
        p.stampa();
    }
}
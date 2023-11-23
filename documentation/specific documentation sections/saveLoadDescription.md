Slučaj upotrebe: Save / load

    Kratak opis: 
        Omogućuje korisniku da učita raspored i da sačuva izmene na njemu.

    Akteri: 
        Korisnik

    Preduslovi: 
        Aplikacija je pokrenuta i prikazuje se početni prozor.

    Osnovni tok:
        LOAD:
            1. Korisnik pokreće aplikaciju
            2. Aplikacija prikazuje listu rasporeda (sa svim podešavanjima, TO-DO listi, ...) koje korisnik može da učita
            3. Korisnik bira raspored
            4. Raspored se učitava i prikazuje

        SAVE: 
            1. Nakon izmena rasporeda korisnik pritiska dugme save
            2. Aplikacija čuva izmenjeni raspored u odgovarajućem formatu tako da on može ponovo da se učita
            3. Aplikacija obaveštava korisnika da je raspored uspešno sačuvan.

    Alternativni tokovi: 
        A1: Ispisuje se poruka o neuspehu.

    Specijalni zahtevi : /
    Dodatne informacije: /
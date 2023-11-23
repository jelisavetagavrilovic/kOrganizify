Slučaj upotrebe: Smart plan

    Kratak opis: 
        Omogućuje automatsko planiranje rasporeda.

    Akteri:
        Korisnik

    Preduslovi:
        Aplikacija je pokrenuta i prikazan je glavni prozor.

    Osnovni tok: 
        1. Aplikacija prikazuje glavni prozor (raspored).
        2. Korisnik pristupa sekciji ‘smart plan’.
        3. Korisnik dodaje sve događaje koji već nisu u rasporedu, tj događaje za koje nema određen dan kada treba da budu izvršene, već je samo bitno da budu urađene u toku nedelje.
        4. Korisnik pritiska dugme ‘create’.
        5. Aplikacija generiše više mogućih rasporeda.
                5.1. Korisnik bira najpogodniji raspored.
                5.2. Ukoliko korisniku ne odgovara ni jedan raspored, ima mogućnost da aplikacija ponovo generiše više mogućih rasporeda.
                5.3. Korisnik bira dugme odustani ukoliko želi da odustane.
        6. Aplikacija čuva raspored u memoriju.

    Alternativni tokovi:
        A1: Ispisuje se poruka o grešci i korisnik je vraćen na standardni tok aplikacije.

    Specijalni zahtevi : /
    Dodatne informacije:  /
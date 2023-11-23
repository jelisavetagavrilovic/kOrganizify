Slučaj upotrebe: Sinhronizacija

    Kratak opis: 
        Spajanje i reorganizacija rasporeda korisnika i njegovog prijatelja kako bi mogli da u isto vreme idu na neki događaj.

    Akteri: 
        Korisnik, Prijatelj

    Preduslovi: 
        Aplikacija prikazuje glavni prozor i lista prijatelja nije prazna.

    Osnovni tok: 
        1. Korisnik kreira dogadjaj
        2. Korisnik pritiska dugme za dodavanje prijatelja
            2.1. Aplikacija prikazuje listu prijatelja
        3. Korisnik bira prijatelja
            3.1. Aplikacija šalje poziv prijatelju sa terminom
                3.1.1. Ukoliko prijatelj odgovori da mu odgovara, događaj se dodaje u raspored obojici
                3.1.2. Ukoliko prijatelj odgovori da mu ne odgovara, šalje se informacija korisniku da prosledi novi termin
            3.2. Ovaj postupak se ponavlja dok se ne usaglase

    Alternativni tokovi: 
        A1: Dogadjaj se briše. Korisnik i prijatelj se obaveštavaju o brisanju i vraćaju se na glavni prozor.

    Specijalni zahtevi : /
    Dodatne informacije: /
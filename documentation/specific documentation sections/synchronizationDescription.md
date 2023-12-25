Slučaj upotrebe: Sinhronizacija

    Kratak opis: 
        Spajanje i reorganizacija rasporeda korisnika i njegovog prijatelja kako bi mogli da u isto vreme idu na neki događaj.

    Akteri: 
        Korisnik, Prijatelj

    Preduslovi: 
        Aplikacija prikazuje glavni prozor i lista prijatelja nije prazna.

    Osnovni tok:
        1. Korisnik bira prijatelja sa kojim zeli da se sinhronizuje.
        2. Korisnik unosi ime dogadaja i koliko dugo zeli da traje dogadaj.
        3. Aplikacija salje poziv prijatelju s terminom.
            3.1: Ukoliko prijatelj odgovori da mu odgovara, aplikacija pronalazi sve zajedniˇcke slobodne termine za oba korisnika.
                3.1.1: Aplikacija ˇsalje redom slobodne termine korisniku i prijatelju.
                    3.1.1.1: Ako dode do usaglaˇsavanja, dogadaj se upisuje u kalendar.
                    3.1.1.2: Ako ne dode do usaglaˇsavanja, ˇsalje se naredni slobodni termin.
                3.1.2: Ukoliko se prode kroz sve termine i ne dode do usaglaˇsavanja, ˇsalje se odgovaraju ́ca poruka korisniku i prijatelju.
            3.2: Ukoliko prijatelj odgovori da mu ne odgovara, aplikacija ˇsalje odgovaraju ́cu poruku korisniku.
        4. Funkcionalnost se prekida nakon obavljenog zadatka.

    Alternativni tokovi:

    A1: /

    Specijalni zahtevi :/

    Dodatne informacije: /
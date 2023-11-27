Slučaj upotrebe: Kreiranje događaja

    Kratak opis:
        Korisnik dodaje novi događaj u svoj kalendar kako bi organizovao svoje obaveze. Obuhvata kreiranje, modifikaciju i brisanje događaja, uz opcije prioritizacije, kategorizacije i postavljanja podsetnika.

    Akteri:
        Korisnik

    Preduslovi:  
        Kalendar je otvoren i korisnik ima pristup kalendaru.

    Osnovni tok:
    
        1. Korisnik odabire dan u kalendaru.
            1.1: Ako je odabrani dan ve ́c ima dogadaje:
                1.1.1: Korisnik bira postoje ́ci dogadaj koji ˇzeli modifikovati ili obrisati.
                    1.1.1.1: Korisnik vrˇsi modifikaciju dogadaja (naziv, opis, datum, vreme, prioritet, kategorija).
                    1.1.1.2: Korisnik postavlja opcioni podsetnik.
                    1.1.1.3: Korisnik ˇcuva izmene.
                    1.1.1.4: Ako korisnik odustane od izmena, korak se zavrˇsava.
                    1.1.1.5: Korisnik bira opciju brisanja dogadaja.
                    1.1.1.6: Aplikacija potvrduje korisnikovu nameru brisanja.
                    1.1.1.7: Korisnik potvrduje brisanje.
                    1.1.1.8: Aplikacija briˇse dogadaj.
                1.1.2: Ako korisnik odustane od modifikacija ili brisanja, korak se zavrˇsava.
            1.2: Ako je odabrani dan prazan:
                1.2.1: Korisnik unosi osnovne informacije o novom dogadaju: naziv, opis, datum i vreme.
                1.2.2: Opciono, korisnik dodaje prioritet i kategoriju.
                1.2.3: Opciono, korisnik postavlja podsetnik.
                1.2.4: Korisnik ˇcuva novi dogadaj

    Alternativni tokovi:  
    Aplikacija nije uspela da ispuni željeni zahtev (npr., greška prilikom čuvanja).Aplikacija obaveštava korisnika o neuspehu, i korisnik se vraća na standardni tok rada aplikacije.

    Specijalni zahtevi: /
  
    Dodatne informacije: /

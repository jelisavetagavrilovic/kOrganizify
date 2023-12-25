Slučaj upotrebe: Kreiranje događaja

    Kratak opis:
        Korisnik dodaje novi događaj u svoj kalendar kako bi organizovao svoje obaveze. Obuhvata kreiranje, modifikaciju i brisanje događaja, uz opcije prioritizacije, kategorizacije i postavljanja podsetnika.

    Akteri:
        Korisnik

    Preduslovi:  
        Kalendar je otvoren i korisnik ima pristup kalendaru.

    Osnovni tok:
    
       1. Korisnik odabire dan u kalendaru.
        1.1. Ako je odabrani dan ve ́c ima dogadaje:
            1.1.1. Korisnik bira postojeci dogadaj koji zeli modifikovati.
                1.1.1.1. Korisnik vrsi modifikaciju dogadaja (naziv, opis, datum, vreme, prioritet, kategorija).
                1.1.1.2. Korisnik cuva izmene.
                1.1.1.3. Ako korisnik odustane od izmena, korak se zavrsava.
            1.1.2. Korisnik bira postoje ́ci dogadaj koji ˇzeli obrisati.
                1.1.2.1. Aplikacija potvrduje korisnikovu nameru brisanja.
                1.1.2.2. Korisnik potvrduje brisanje.
                1.1.2.3. Aplikacija brise dogadaj.
            1.1.3. Ako korisnik odustane od modifikacija ili brisanja, korak se zavrsava.
        1.2. Ako je odabrani dan prazan:
            1.2.1. Korisnik unosi osnovne informacije o novom dogadaju: naziv, opis, datum i vreme.
            1.2.2. Opciono, korisnik dodaje prioritet i kategoriju.
            1.2.3. Korisnik ˇcuva novi dogadaj.
                
    Alternativni tokovi:
        A1: Ispisuje se poruka o greˇsci i korisnik je vra ́cen na standardni tok aplikacije.
    
    Specijalni zahtevi : /
    
    Dodatne informacije: /

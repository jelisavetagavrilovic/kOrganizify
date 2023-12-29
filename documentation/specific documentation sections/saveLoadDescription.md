Slučaj upotrebe: Čuvanje i učitavanje podataka

    Kratak opis: 
        Omogućuje korisniku da učita raspored i da sačuva izmene na njemu.

    Akteri: 
        Korisnik

    Preduslovi: 
        Aplikacija je pokrenuta i prikazuje se početni prozor.

    Osnovni tok:
        1. Korisnik pokreće aplikaciju.
        2. Unosi korisničko ime i šifru.
            2.1. Ako postoji korisnik:
                2.1.1. Učitava se prozor sa njegovim podacima(sa kalendarom, svim podešavanjima, TO-DO listi, ...)
                2.1.2. Izvršava izmene koje želi.
            2.2. Ako ne postoji korisnik:
                2.2.1. Učitava se prozor koji nema podatke.
                2.2.2. Izvršava izmene koje želi.
        3. Korisnik klikne dugme 'Logout' kako bi se izlogovao i tek tada se čuvaju podaci.

    Alternativni tokovi: 
        A1: Ispisuje se poruka o neuspehu.

    Specijalni zahtevi : /
    Dodatne informacije: /
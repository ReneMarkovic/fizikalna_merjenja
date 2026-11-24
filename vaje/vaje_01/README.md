# Vaja 2 – Merjenje napetosti, toka in odziva RC-člena

[Delovni list s shemami vezav, primerom kode in vprašanji (DOCX)](Vaje_FM_02.docx)

[Arduino skica (Vaja02.ino)](Vaja02/Vaja02.ino)

Za vajo je predvidenih 90–120 minut. Z ESP32-C6 boste vzorčili napetost in rezultate prikazali v Arduino Serial Plotterju. Uporabite GPIO3 za vzbujanje vezja, GPIO2 za merjenje napetosti in skupni GND. Pred vezavo preberite razdelek o opremi in varnosti v delovnem listu.

1. **Delilnik napetosti.** Izmerite napetost med počasnim preklapljanjem digitalnega izhoda. Rezultat primerjajte z multimetrom in preizkusite različne intervale vzorčenja.
2. **Merjenje toka.** Iz padca napetosti na merilnem uporu 220 Ω izračunajte tok in ga primerjajte s pričakovano vrednostjo.
3. **RC-člen.** Opazujte polnjenje in praznjenje kondenzatorja. Ocenite časovno konstanto iz grafa in jo primerjajte z izračunom `τ = RC`.

V Arduino IDE odprite `Vaja02/Vaja02.ino`. V vrstici `NALOGA` izberite `Naloga::Delilnik`, `Naloga::Tok` ali `Naloga::RC` glede na priključeno vezje. Naložite skico in odprite Serial Plotter pri 115200 baud. Pri delilniku in RC-členu sta prikazani nazivna referenca izhoda in izmerjena napetost v mV, pri merjenju toka pa tok v mA. Interval vzorčenja spremenite s konstanto `VZOREC_MS`.

Oddajte skico `.ino`, projektni `README.md` in vsaj dva posnetka Serial Plotterja za delilnik in RC-člen. Vključite izračune, primerjavo z meritvami, oceno časovne konstante in razlago razlike med ločljivostjo in natančnostjo ADC. Delo zabeležite v najmanj dveh smiselnih Git commitih.


ojoj

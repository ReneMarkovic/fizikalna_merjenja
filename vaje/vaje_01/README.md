# Vaja 2 – Merjenje napetosti, toka in odziva RC-člena

[Delovni list s shemami vezav, primerom kode in vprašanji (DOCX)](Vaje_FM_02.docx)

Za vajo je predvidenih 90–120 minut. Z ESP32-C6 boste vzorčili napetost in rezultate prikazali v Arduino Serial Plotterju. Uporabite GPIO3 za vzbujanje vezja, GPIO2 za merjenje napetosti in skupni GND. Pred vezavo preberite razdelek o opremi in varnosti v delovnem listu.

1. **Delilnik napetosti.** Izmerite napetost med počasnim preklapljanjem digitalnega izhoda. Rezultat primerjajte z multimetrom in preizkusite različne intervale vzorčenja.
2. **Merjenje toka.** Iz padca napetosti na merilnem uporu 220 Ω izračunajte tok in ga primerjajte s pričakovano vrednostjo.
3. **RC-člen.** Opazujte polnjenje in praznjenje kondenzatorja. Ocenite časovno konstanto iz grafa in jo primerjajte z izračunom `τ = RC`.

Oddajte skico `.ino`, projektni `README.md` in vsaj dva posnetka Serial Plotterja za delilnik in RC-člen. Vključite izračune, primerjavo z meritvami, oceno časovne konstante in razlago razlike med ločljivostjo in natančnostjo ADC. Delo zabeležite v najmanj dveh smiselnih Git commitih.

Instrucciones
-----------------
Consulten la página https://www.numwrite.com/search.html para ver como se escriben los números en inglés
-----------------
Antes de subir algo a master, ejecuten el comando make.
- Si os da errores, arreglarlos!!
- No se sube código que no compile!!.
- Si quereis subir código que rompe la compilación, subidlo comentado. 
-----------------

---------------------------------------------------------------------------------
translate("123,456")
    => mask("123,456") => 
        unidades_mil(123450), unidades_mil(123400), unidades_mil(123000), unidades_mil(120000), unidades_mil(100,000) => mil                   
    => translate(123) unidades_mil(123,456), translate(456)
    => translate(123) 
        => unidades_mil(123) => unidades_mil(120) => unidades_mil(100) => cien
        => translate("1") unidades_mil(123) translate(23)
    => translate(456)
        => unidades_mil(450) => unidades_mil(400) => unidades_mil(100) => cien
        => translate("4") unidades_mil(456) translate(56)
---------------------------------------------------------------------------------
translate("512,456") => mediollón docemil, cuatro cientos 50 y 60
Tenemos:
100
1000
500,000 => mediollón => un mediollón 23 mil  
1,000,000
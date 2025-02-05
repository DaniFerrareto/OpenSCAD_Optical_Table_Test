module funcao_2d_array_cilindros(r,d,h,nx,ny,geo,res,nome="Conjunto 1"){
    //----- FUNÇÃO ARRAY 2D DE CILÍNDROS -----//
    /*
    Forneça: 
        Raio dos cilíndros: r
        Distância entre os centros de cada cilíndro: d
        Altura dos cilíndros: h
        Quantidade de cilíndros em ambas as direções: nx, ny
        Resolução dos cilíndros: res
    Selecione a geometria:
        Retangular: geo=1
        Hexagonal: geo=2
    Dê um nome para seu conjunto de cilíndros: nome
    */
    if (d<2*r){
        text("Error!");
        translate([0,-15,0])text("Verify your specified dimensions.");
    }else{
        // Olhe na aba console
        echo("Nome: ", nome);
        echo();
        echo("Quantidade de Cilíndros (nx*ny):");
        echo(nx*ny);
        echo();
    
        if(geo==1){
            for(j=[0:1:ny-1]){
                for(i=[0:1:nx-1]){
                    translate([i*d,j*d,0])cylinder(h,r,r,$fn=res);
                }
            }
            echo("Para essa geometria retangular, as dimensões são ([x=(nx-1)*d+2*r,y=(ny-1)*d+2*r,z=h]):");
            echo("x=",(nx-1)*d+2*r,"y=",(ny-1)*d+2*r,"z=",h);
            echo();
        }else if(geo==2){
            for(j=[0:1:ny-1]){
                for(i=[0:1:nx-1]){
                    translate([i*d+(j%2)*d*cos(60),j*d*sin(60),0])cylinder(h,r,r,$fn=res);
                }
            }
            echo("Para essa geometria hexagonal, as dimensões são ([x=(nx-1+cos(60))*d+2*r,y=(ny-1)*d*sin(60)+2*r,z=h]):");
            echo("x=",(nx-1+cos(60))*d+2*r,"y=",(ny-1)*d*sin(60)+2*r,"z=",h);
            echo();
        }else{
            text("Error!");
            translate([0,-15,0])text("Please, choose a valid geometry number.");
        }
    }
}

// Vamos fazer um teste para uma mesa óptica milimétrica de furos M6 (uma folga de 0.15) e uma distância de 25mm entre furos
difference(){
    translate([-6-0.3,-6-0.3,0])cube([233.1+6+0.3,233.1+6+0.3,2]);
    #funcao_2d_array_cilindros(6/2+0.15,25.2,2,10,10,1,100,"Mesa Óptica");   
}

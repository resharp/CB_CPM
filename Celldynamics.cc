/*
    This file describes the internal dynamics of the CPM cells, where:
        vol = current volume of the cell
        divvol = division volume of cell
        tarvol = current targetvolume of cell
        X = actual concentration of molecule X
        Y = actual concentration of molecule Y
        curX = current concentration of molecule X
        curY = current concentration of molecule Y

        ... and more parameters that are defined in parfile.cfg

    Go ahead and change things, but don't forget to make ;)
*/

if((tarvol-vol) < 10 && X > 0.0) // Some conditions before tar-volume can be bumped
{
	tarvol+=(Y_growth_contribution)*(curY/vol)/((curY/vol)+0.10);
}

tarvol -= shrink_rate;

X += ( rX*curX*(vol-bxx*curX-byx*curY)/vol - dX*curX ) * speed_internal_dynamics;

Y +=  (rY*curY*(vol-byy*curY-bxy*curX)/vol - dY*curY ) * speed_internal_dynamics;

if (X < 0.0) X = 0.0;
if (Y < 0.0) Y = 0.0;

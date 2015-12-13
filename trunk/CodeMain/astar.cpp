/*!
 * \brief astar.
 * \details Implémentation du pathfinding
 * \version 1
 * \date 2015-12-09
 */
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib> 
#include <cstdio>
#include "astar.hpp"


using namespace std;

	 
		/*!
		 * Constructeur d'un objet node, utilisé pour calculer le chemin
		 * @param [in] xp valeur à donner à xPos
		 * @param [in] yp valeur à donner à yPos
		 * @param [in] l valeur à donner à level
		 * @param [in] p valeur à donner à priorite
		 * @param [out] xPos position actuelle en abscisse
		 * @param [out] yPos position actuelle en ordonnée
		 * @param [out] level valeur contenant la distance parcourue pour arriver ici
		 * @param [out] priority distance déjà parcourue plus estimation de la distance restante, plus la valeur est faible plus la priorité est grande
		 */ 
		node::node(){
		}
        node::node(int xp, int yp, int l, int p) 
            {xPos=xp; yPos=yp; level=l; priority=p;}
		/*!
		 * Getter pour obtenir la position en x
		 * @param [in] aucun
		 * @return xPos
		 */ 
        int node::getxPos() const {return xPos;}
        
        /*!
		 * Getter pour obtenir la position en y
		 * @param [in] aucun
		 * @return yPos
		 */
        int node::getyPos() const {return yPos;}
        
         /*!
		 * Getter pour obtenir la distance déjà parcourue
		 * @param [in] aucun
		 * @return level
		 */
        int node::getLevel() const {return level;}
        
         /*!
		 * Getter pour obtenir la priorite du node
		 * @param [in] aucun
		 * @return priority
		 */
        int node::getPriority() const {return priority;}

		 /*!
		 * Méthode mettant à jour la priorité d'un node
		 * @param [in] xDest La coordonnée en abscisse du point d'arrivée
		 * @param [in] yDest La coordonnée en ordonnée du point d'arrivée
		 * @param [out] priority mis à jour en utilisant l'estimation
		 */
        void node::updatePriority(const int & xDest, const int & yDest)
        {
             priority=level+estimate(xDest, yDest)*10; 
		}
        
       /*!
		 * Méthode estimant la distance restante avant l'arrivée en calculant la distance euclidienne
		 * @param [in] xDest La coordonnée en abscisse du point d'arrivée
		 * @param [in] yDest La coordonnée en ordonnée du point d'arrivée
		 * @return dist la distance calculée
		 */
        const int & node::estimate(const int & xDest, const int & yDest) const
        {
            static int xd, yd, dist;
            xd=xDest-xPos;
            yd=yDest-yPos;         

            dist=static_cast<int>(sqrt(xd*xd+yd*yd));

            return(dist);
        }


/*!
 * Surcharge de l'opérateur < sur des nodes, pour comparer leurs priorites
 */
bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
}

/*!
 * Calcul de chemin le plus court
 * @param [in]  xStart la coordonnée de départ en abscisse
 * @param [in]  yStart la coordonnée de départ en ordonnée
 * @param [in]  xFinish la coordonnée d'arrivée en abcisse
 * @param [in]  yFinish la coordonnée d'arrivée en abcisse
 * @param [in]  collision_map vecteur représentant la carte avec des coordonnées accessibles ou non
 * @return Une chaine de caractères décrivant le chemin à suivre, chaque caractère(0, 1, 2 ou 3) représente un mouvement
 * @param [out] dir le nombre de directions possibles. Ici 4, serait 8 si on utilisait les diagonales
 * @param [out] dx tableau contenant les coordonnées en x pour chaque mouvement 
 * @param [out] dy tableau contenant les coordonnées en y pour chaque mouvement 
 * @param [out] n taille en hauteur de la carte
 * @param [out] m taille en largeur de la carte
 * @param [out] closed_nodes_map carte contenant les nodes déjà évalués et rejetés
 * @param [out] open_nodes_map carte contenant les nodes non évalués
 * @param [out] dir_map
 * @param [out] priority_queue queue contenant les nodes navigables
 * @param [out] pqi index de la queue de priorite
 * 
 * 
*/
string pathFind( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish, vector<vector<int> > collision_map )
{	
        const int dir=4; 
        static int dx[dir]={1, 0, -1, 0};
        static int dy[dir]={0, 1, 0, -1};
        
	int n  = collision_map.size();
	int m = collision_map.at(0).size();
        
	int closed_nodes_map[n][m];
	int open_nodes_map[n][m]; 
	int dir_map[n][m]; 
	
	

    static priority_queue<node> pq[2]; 
    static int pqi; 
    static node* n0;
    static node* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi=0;

    
    for(y=0;y<m;y++)
    {
        for(x=0;x<n;x++)
        {
            closed_nodes_map[x][y]=0;
            open_nodes_map[x][y]=0;
        }
    }

    
    n0=new node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    open_nodes_map[xStart][yStart]=n0->getPriority(); 
	delete n0;
	
    
    while(!pq[pqi].empty())
    {
      
        n0=new node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(), 
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pqi].pop(); 
        open_nodes_map[x][y]=0;
        
        closed_nodes_map[x][y]=1;

        
        if(x==xFinish && y==yFinish) 
        {
           
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j=dir_map[x][y];
                c='0'+(j+dir/2)%dir;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }

            
            delete n0;
            
            while(!pq[pqi].empty()) pq[pqi].pop();           
            return path;
        }

        
        for(i=0;i<dir;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];

            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || collision_map[xdx][ydy]==0 
                || closed_nodes_map[xdx][ydy]==1))
            {
                
                m0=new node( xdx, ydy, n0->getLevel(), 
                             n0->getPriority());
               
                m0->updatePriority(xFinish, yFinish);

              
                if(open_nodes_map[xdx][ydy]==0)
                {
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    pq[pqi].push(*m0);
                    delete m0;
                
                    dir_map[xdx][ydy]=(i+dir/2)%dir;
                }
                else if(open_nodes_map[xdx][ydy]>m0->getPriority())
                {
                  
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                  
                    dir_map[xdx][ydy]=(i+dir/2)%dir;

                    
                    while(!(pq[pqi].top().getxPos()==xdx && 
                           pq[pqi].top().getyPos()==ydy))
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pq[pqi].pop(); 
                    
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); 
                    delete m0;
                }
                else delete m0; 
            }
        }
        delete n0; 
    }
    return ""; 
}

    					 

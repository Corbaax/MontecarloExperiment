# Esperimenti di calcolo parallelo
## Introduzione
*Presentazione del problema, _literature review_ (stato dell'arte) e obiettivi dello studio*

Il calcolo parallelo è una tecnica che permette l'esecuzione di più processi computazionali simultaneamente. Consiste nel dividere un carico computazionale complesso in sotto-attività più semplici e spesso indipendenti tra di loro, permettendo a più unità di elaborazione di collaborare aumentando riducendo i tempi di esecuzione.
Questa tipologia di calcolo è nativa delle unità di calcolo grafico (GPU) ma può essere impiegata su processori più classici (CPU) anche se con minor efficacia.

In questo studio si è voluto sperimentare l'implementazione di un carico computazionale pesante e la successiva estensione con paradigma di calcolo parallelo al fine di apprenderne il funzionamento e analizzare il comportamento alla variazione di hardware e risorse. 
## Metodi
*Descrizione dettagliata di come è stata svolta la ricerca (esperimenti, analisi dati, modelli)*

Per prima cosa è stato deciso il carico computazionale da implementare, nello specifico si è scelto di utilizzare un algoritmo di stima del valore di $\pi$ utilizzando il metodo di Montecarlo.
Il metodo di Montecarlo è una statistica che permette di stimare l'area di una funzione matematica continua in un intervallo definito, di cui si conosce il massimo valore.

$$MonteCarlo_{[a,b]}(f(x)) \approx \int_a^b f(x) dx$$

Generando dei punti casuali all'interno di un rettangolo immaginario che si estende sull'asse x con intervallo $[a,b]$ e sull'asse y $[0,max(f(x))]$ ci aspettiamo che la probabilità che un punto ricada all'interno dell'area della funzione sia proporzionale all'area stessa.

$$
\begin{aligned}
 X \sim U[a,b] \\ 
 Y \sim U[0,max(f(x))]\\ \\
 Z = 
	 \begin{cases}
	 1 & se & Y \leq f(X) \\
	 0 & se & Y \gt f(X)
	 \end{cases}
 \\ \\
 Z \sim B(p) \\ \\
 p = \frac{\int_a^bf(x)dx}{max(f(x)) * (b-a)}
\end{aligned}
$$

Per costruire lo stimatore di $\pi$  utilizzo una funzione ricavata dalla formula canonica della circonferenza che descrive un quarto della circonferenza totale, precisamente la porzione presente nel primo quadrante. Il rettangolo che inscrive l'intervallo della funzione corrisponde da un quadrato di lato $r$.
La formula per l'area della circonferenza è nota, nel caso della funzione è divisa per quattro $\frac{\pi r^2}{4}$ mentre l'area del quadrato è pari a $r^2$. sostituendo i termini nell'equazione di $p$ otteniamo:

$$
p = \frac{\pi r^2}{4} * \frac{1}{r^2} = \frac{\pi}{4}
$$

Utilizzo la media campionaria della $v.a. Z$ per stimare il parametro ignoto $p$

$$
\mathbb{E}[Z] = \frac{\sum_{i \in Exp}{Z_i}}{|Exp|} = p
$$

Per calcolare la stima di $\pi$ utilizzo la formula:

$$
\hat{\pi} = p * 4
$$

Per effettuare gli esperimenti è stato scritto un codice in linguaggio C con il paradigma OMP, implementando prima una versione seriale dell'algoritmo seguita da una fase di testing per verificare il corretto funzionamento.
Successivamente è stato analizzato l'algoritmo per identificare le sezioni di codice parallelizzabili.
Nel programma prodotto l'esperimento viene diviso in sotto-esperimenti la cui dimensione del campione è minore, ogni thread si occupa di eseguire un sotto-esperimento producendo un "sottoprodotto". Al termine della sezione parallela tutti i sottoprodotti vengono uniti ottenendo la soluzione al problema originale.
## Risultati
*Presentazione oggettiva dei dati raccolti, senza interpretazioni.*
## Discussione
*Interpretazione dei risultati, confronto con la letteratura e implicazioni.*

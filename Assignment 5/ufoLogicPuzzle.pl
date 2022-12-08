day(tuesday).
day(wednesday).
day(thursday).
day(friday).

earlier(tuesday, wednesday).
earlier(tuesday, thursday).
earlier(tuesday, friday).
earlier(wednesday, thursday).
earlier(wednesday, friday).
earlier(thursday, friday).

person(klaatu).
person(gort).
person(barada).
person(nikto).

saw(balloon).
saw(frisbee).
saw(clothesline).
saw(watertower).

% Solve the puzzle.
solve :-
    % Each of the four reported his or her sighting on a different day
    day(KlaatuDay), day(GortDay), day(BaradaDay), day(NiktoDay),
    all_different([KlaatuDay, GortDay, BaradaDay, NiktoDay]),

    % government stepped in and was able to give each person a different, plausible explanation of what he or she had “really" seen
    saw(KlaatuSaw), saw(GortSaw), saw(BaradaSaw), saw(NiktoSaw),
    all_different([KlaatuSaw, GortSaw, BaradaSaw, NiktoSaw]),

    Triples = [ [klaatu, KlaatuSaw, KlaatuDay],
                [gort, GortSaw, GortDay],
                [barada, BaradaSaw, BaradaDay],
                [nikto, NiktoSaw, NiktoDay] ],

    % 1. Mr. Klaatu made his sighting at some point earlier in the week than the one who saw the balloon,
    %    but at some point later in the week than the one who spotted the Frisbee (who isn't Ms. Gort).
    member([_, balloon, BalloonDay], Triples), member([_, frisbee, FrisbeeDay], Triples),
    earlier(KlaatuDay, BalloonDay), earlier(FrisbeeDay, KlaatuDay),
    \+ member([klaatu, balloon, _], Triples), \+ member([klaatu, frisbee, _], Triples), \+ member([gort, frisbee, _], Triples),
    
    % 2. Friday's sighting was made by either Ms. Barada or the one who saw a clothesline
    %    (or both).
    (
    	member([barada, _, friday], Triples);
    	member([_, clothesline, friday], Triples)
    ),

    % 3. Mr. Nikto did not make his sighting on Tuesday.
    \+ member([nikto, _, tuesday], Triples),

    % 4. Mr. Klaatu isn't the one whose object turned out to be a water tower.
    \+ member([klaatu, watertower, _], Triples),

    tell(klaatu, KlaatuSaw, KlaatuDay),
    tell(gort, GortSaw, GortDay),
    tell(barada, BaradaSaw, BaradaDay),
    tell(nikto, NiktoSaw, NiktoDay).

% Succeed if all elements of the argument list are bound and different.
% Fail if any elements are unbound or equal to some other element.
all_different([H | T]) :- member(H, T), !, fail.        % (1)
all_different([_ | T]) :- all_different(T).             % (2)
all_different([_]).                                     % (3)

% Write out an English sentence with the solution.
tell(X, Y, Z) :-
    write(X), write(' saw '), write(Y), write(' on '), write(Z), nl.
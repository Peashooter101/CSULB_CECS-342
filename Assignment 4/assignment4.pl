% Last week, four UFO enthusiasts made sightings of unidentified flying objects in their neighborhood.
% Each of the four reported his or her sighting on a different day,
%    and soon the neighborhood was abuzz with rumors of little green men.
% By the weekend, though, the government stepped in and was able to give each person a different,
%    plausible explanation of what he or she had “really" seen.
% Can you determine the day (Tuesday through Friday) each person sighted a UFO, as well as the object that it turned out to be?

% 1. Mr. Klaatu made his sighting at some point earlier in the week than the one who saw the balloon,
%    but at some point later in the week than the one who spotted the Frisbee (who isn't Ms. Gort).
% 2. Friday's sighting was made by either Ms. Barada or the one who saw a clothesline (or both).
% 3. Mr. Nikto did not make his sighting on Tuesday.
% 4. Mr. Klaatu isn't the one whose object turned out to be a water tower.

% Order Days: tuesday wednesday thursday friday
earlier(tuesday, wednesday).
earlier(tuesday, thursday).
earlier(wednesday, thursday).
earlier(tuesday, friday).
earlier(wednesday, friday).
earlier(thursday, friday).

% People: klaatu, gort, barada, nikto
% Objects: balloon, frisbee, clothesline, watertower

on(nikto, X) :- X = wednesday; X = thursday; X = friday.            % Statement 3
saw(klaatu, X) :- X = balloon; X = frisbee; X = clothesline.        % Statement 4
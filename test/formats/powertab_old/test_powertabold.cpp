/*
  * Copyright (C) 2013 Cameron White
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <catch.hpp>

#include <formats/powertab_old/powertaboldimporter.h>
#include <formats/powertab_old/powertabdocument/powertabdocument.h>
#include <score/score.h>

TEST_CASE("Formats/PowerTabOldImport/SongHeader", "")
{
    Score score;
    PowerTabOldImporter importer;
    importer.load("data/song_header.ptb", score);

    const SongData &data = score.getScoreInfo().getSongData();

    REQUIRE(data.getTitle() == "Some Title");
    REQUIRE(data.getArtist() == "Some Artist");

    REQUIRE(data.isVideoRelease());

    REQUIRE(data.getAuthorInfo().getComposer() == "Some Author");
    REQUIRE(data.getAuthorInfo().getLyricist() == "Some Lyricist");

    REQUIRE(data.getArranger() == "Some Arranger");
    REQUIRE(data.getTranscriber() == "Some Transcriber");
    REQUIRE(data.getCopyright() == "2001");
    REQUIRE(data.getLyrics() == "Some lyrics");
    REQUIRE(data.getPerformanceNotes() == "Some notes.");
}

TEST_CASE("Formats/PowerTabOldImport/Guitars", "")
{
    Score score;
    PowerTabOldImporter importer;
    importer.load("data/guitars.ptb", score);

    REQUIRE(score.getPlayers().size() == 2);
    REQUIRE(score.getInstruments().size() == 2);

    const Player &player1 = score.getPlayers()[0];
    const Player &player2 = score.getPlayers()[1];
    REQUIRE(player1.getDescription() == "First Player");
    REQUIRE(player2.getDescription() == "Second Player");
    REQUIRE(player2.getTuning().getStringCount() == 7);

    REQUIRE(score.getInstruments()[0].getDescription() == "Electric Guitar (clean)");
}

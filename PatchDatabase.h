/*
   Copyright (c) 2020 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include <memory>
#include <vector>

#include "Synth.h"

#include "ProgressHandler.h"
#include "PatchHolder.h"

namespace midikraft {

	class PatchDatabase {
	public:
		PatchDatabase();
		~PatchDatabase();

		int getPatchesCount(Synth *activeSynth);
		void getPatchesAsync(Synth *activeSynth, std::function<void(std::vector<PatchHolder> const &)> finished, int skip, int limit);
		size_t mergePatchesIntoDatabase(Synth *activeSynth, std::vector<PatchHolder> &patches, std::vector<PatchHolder> &outNewPatches, ProgressHandler *progress);
		bool putPatch(Synth *activeSynth, PatchHolder const &patch);
		bool putPatches(Synth *activeSynth, std::vector<PatchHolder> const &patches);

		void runMigration(Synth * activeSynth);

	private:
		class PatchDataBaseImpl;
		std::unique_ptr<PatchDataBaseImpl> impl;
		ThreadPool pool_;
	};

}

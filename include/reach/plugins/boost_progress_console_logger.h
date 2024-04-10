/*
 * Copyright 2019 Southwest Research Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef REACH_PLUGINS_BOOST_PROGRESS_CONSOLE_LOGGER_H
#define REACH_PLUGINS_BOOST_PROGRESS_CONSOLE_LOGGER_H

#include <reach/interfaces/logger.h>

#include <boost/shared_ptr.hpp>
#include <boost/timer/progress_display.hpp>
#include <mutex>

namespace reach
{
/**
 * @brief Thread-safe logger that prints messages to the console via stdout, with boost progress bar progress logging
 */
class BoostProgressConsoleLogger : public Logger
{
public:
  BoostProgressConsoleLogger();

  void setMaxProgress(unsigned long max_progress) override;
  void printProgress(unsigned long progress) const override;
  void printResults(const ReachResultSummary& results) const override;
  void print(const std::string& message) const override;

protected:
  mutable std::mutex mutex_;
  mutable boost::shared_ptr<boost::timer::progress_display> display_;
};

struct BoostProgressConsoleLoggerFactory : public LoggerFactory
{
  Logger::Ptr create(const YAML::Node& /*config*/) const override;
};

}  // namespace reach

#endif  // REACH_PLUGINS_BOOST_PROGRESS_CONSOLE_LOGGER_H

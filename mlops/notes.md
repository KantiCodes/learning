# Tools:
Splunk Technologly mainly used by Data Analyst, Grafana tool used by software developers. Splunk has a nice language for querying logs efficently (faster than grafana) aggregates etc... Grafana is more for visualizing data, it's a dashboard tool.



# Online monitoring


# Tools
- data drift: ALibi Detect
- Data quality with alterting: Great Expectations
- Continuous training: River
- Model Serving/Deployment/Tracking/Monitoring: MLflow
- Data versioning and lineage: DVC(naive lineage), MLFlow(lineage can be implemented without limits)
- Continous monitoring of data in production: Edvidently, Weights and Biases
- Orchestrating the pipeline:
- - Airflow:supposably old but actually used many places and good (hard to parametrize)
- - Metaflow: Netflix tool, pythonic, easy to use, good for prototyping, ONLY AWS, NOT MATURE


# Exam:
1. Design a dashboard with KPIs/metrics that we would monitor for the model. In the practical exam implemet a small dashboard (using evidently)